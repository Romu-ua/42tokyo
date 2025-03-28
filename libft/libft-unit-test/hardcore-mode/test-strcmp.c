#include "utils.h"

# define L(str) str
# define SIMPLE_STRCMP simple_strcmp

/* Strcmp uses unsigned semantics for comparison. */
	int
simple_strcmp (const char *s1, const char *s2)
{
  	int ret;

  	while ((ret = *(unsigned char *) s1 - *(unsigned char*) s2++) == 0 && *s1++);
  	return ret;
}

typedef int (*proto_t) (const CHAR *, const CHAR *);

	static int
check_result (impl_t *impl,
	    const CHAR *s1, const CHAR *s2,
	    int exp_result)
{
  	int result = CALL (impl, s1, s2);
  	if ((exp_result == 0 && result != 0)
      		|| (exp_result < 0 && result >= 0)
      		|| (exp_result > 0 && result <= 0))
    {
      	error (0, 0, "Wrong result in function %s %d %d", impl->name,
	     		result, exp_result);
      	ret = 1;
      	return -1;
    }

  	return 0;
}

	static void
do_one_test (impl_t *impl,
	    const CHAR *s1, const CHAR *s2,
	    int exp_result)
{
  	if (check_result (impl, s1, s2, exp_result) < 0)
    	return;
}

	static void
do_test (size_t align1, size_t align2, size_t len, int max_char,
	 	int exp_result)
{
  	size_t i;

  	CHAR *s1, *s2;

  	if (len == 0)
    	return;

  	align1 &= 63;
  	if (align1 + (len + 1) * CHARBYTES >= page_size)
    	return;

  	align2 &= 63;
  	if (align2 + (len + 1) * CHARBYTES >= page_size)
    	return;

  	/* Put them close to the end of page.  */
  	i = align1 + CHARBYTES * (len + 2);
  	s1 = (CHAR *) (buf1 + ((page_size - i) / 16 * 16) + align1);
  	i = align2 + CHARBYTES * (len + 2);
  	s2 = (CHAR *) (buf2 + ((page_size - i) / 16 * 16)  + align2);

  	for (i = 0; i < len; i++)
    	s1[i] = s2[i] = 1 + (23 << ((CHARBYTES - 1) * 8)) * i % max_char;

  	s1[len] = s2[len] = 0;
  	s1[len + 1] = 23;
  	s2[len + 1] = 24 + exp_result;
  	s2[len - 1] -= exp_result;

  	FOR_EACH_IMPL (impl, 0)
    	do_one_test (impl, s1, s2, exp_result);
}

	static void
do_random_tests (void)
{
	UCHAR *p1 = (UCHAR *) (buf1 + page_size - 512 * CHARBYTES);
	UCHAR *p2 = (UCHAR *) (buf2 + page_size - 512 * CHARBYTES);

	for (size_t n = 0; n < ITERATIONS; n++)
	{
	    /* for wcscmp case align1 and align2 mean here alignment
	       in wchar_t symbols, it equal 4*k alignment in bytes, we
	       don't check_strcmp other alignments like for example
	       p1 = (wchar_t *)(buf1 + 1)
	       because it's wrong using of wchar_t type.  */
	    size_t align1 = random () & 31;
	    size_t align2;
	    if (random () & 1)
	      	align2 = random () & 31;
	    else
	      	align2 = align1 + (random () & 24);
	    size_t pos = random () & 511;
	    size_t j = align1 > align2 ? align1 : align2;
	    if (pos + j >= 511)
	      	pos = 510 - j - (random () & 7);
	    size_t len1 = random () & 511;
	    if (pos >= len1 && (random () & 1))
	      	len1 = pos + (random () & 7);
	    if (len1 + j >= 512)
	      	len1 = 511 - j - (random () & 7);
	    size_t len2;
	    if (pos >= len1)
	      	len2 = len1;
	    else
	      	len2 = len1 + (len1 != 511 - j ? random () % (511 - j - len1) : 0);
	    j = (pos > len2 ? pos : len2) + align1 + 64;
	    if (j > 512)
	      	j = 512;
	    for (size_t i = 0; i < j; ++i)
	    {
			p1[i] = random () & 255;
			if (i < len1 + align1 && !p1[i])
		  	{
		    	p1[i] = random () & 255;
		    	if (!p1[i])
		      		p1[i] = 1 + (random () & 127);
		  	}
	    }
	    for (size_t i = 0; i < j; ++i)
	    {
			p2[i] = random () & 255;
			if (i < len2 + align2 && !p2[i])
		  	{
		    	p2[i] = random () & 255;
		    	if (!p2[i])
		      		p2[i] = 1 + (random () & 127);
		  	}
	    }

	    int result = 0;
	    MEMCPY (p2 + align2, p1 + align1, pos);
	    if (pos < len1)
	    {
			if (p2[align2 + pos] == p1[align1 + pos])
		  	{
		    	p2[align2 + pos] = random () & 255;
		    	if (p2[align2 + pos] == p1[align1 + pos])
		      		p2[align2 + pos] = p1[align1 + pos] + 3 + (random () & 127);
		  	}

			if (p1[align1 + pos] < p2[align2 + pos])
		  		result = -1;
			else
		  		result = 1;
	    }
	    p1[len1 + align1] = 0;
	    p2[len2 + align2] = 0;

	    FOR_EACH_IMPL (impl, 1)
	    {
			int r = CALL (impl, (CHAR *) (p1 + align1), (CHAR *) (p2 + align2));
			/* Test whether on 64-bit architectures where ABI requires
		   	   callee to promote has the promotion been done.  */
			asm ("" : "=g" (r) : "0" (r));
			if ((r == 0 && result)
		    		|| (r < 0 && result >= 0)
		    		|| (r > 0 && result <= 0))
		  	{
		    	error (0, 0, "Iteration %zd - wrong result in function %s (align in bytes: %zd, align in bytes: %zd, len1:  %zd, len2: %zd, pos: %zd) %d != %d, p1 %p p2 %p",
			   			n, impl->name, (size_t) (p1 + align1) & 63, (size_t) (p1 + align2) & 63, len1, len2, pos, r, result, p1, p2);
		    	ret = 1;
		  	}
	    }
    }
}

	static void
check_strcmp (void)
{
  	CHAR *s1 = (CHAR *) (buf1 + 0xb2c);
  	CHAR *s2 = (CHAR *) (buf1 + 0xfd8);

  	STRCPY(s1, L("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrs"));
  	STRCPY(s2, L("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijkLMNOPQRSTUV"));

  	/* check_strcmp correct working for negatives values */

  	s1[0] = 1;
  	s2[0] = 1;
  	s1[1] = 1;
  	s2[1] = 1;
  	s1[2] = -1;
  	s2[2] = 3;
  	s1[3] = 0;
  	s2[3] = -1;

  	/* check_strcmp possible overflow bug, actual more for wcscmp */

  	s1[7] = CHAR__MIN;
  	s2[7] = CHAR__MAX;

  	size_t l1 = STRLEN (s1);
  	size_t l2 = STRLEN (s2);

  	for (size_t i1 = 0; i1 < l1; i1++)
    	for (size_t i2 = 0; i2 < l2; i2++)
      	{
			int exp_result = SIMPLE_STRCMP (s1 + i1, s2 + i2);
			FOR_EACH_IMPL (impl, 0)
				check_result (impl, s1 + i1, s2 + i2, exp_result);
      	}
}

static void test_strcmp (void)
{
	it = "ft_strcmp";
	FOR_EACH_IMPL (impl, 1)
	{
  		check (CALL(impl, "", "") == 0, 1);		/* Trivial case. */
  		check (CALL(impl, "a", "a") == 0, 2);		/* Identity. */
  		check (CALL(impl, "abc", "abc") == 0, 3);	/* Multicharacter. */
  		check (CALL(impl, "abc", "abcd") < 0, 4);	/* Length mismatches. */
  		check (CALL(impl, "abcd", "abc") > 0, 5);
  		check (CALL(impl, "abcd", "abce") < 0, 6);	/* Honest miscompares. */
  		check (CALL(impl, "abce", "abcd") > 0, 7);
  		check (CALL(impl, "a\203", "a") > 0, 8);		/* Tricky if char signed. */
  		check (CALL(impl, "a\203", "a\003") > 0, 9);

  		{
    		char buf1[0x40], buf2[0x40];
    		int i, j;
    		for (i=0; i < 0x10; i++)
      			for (j = 0; j < 0x10; j++)
				{
	  				int k;
	  				for (k = 0; k < 0x3f; k++)
	    			{
	      				buf1[k] = '0' ^ (k & 4);
	      				buf2[k] = '4' ^ (k & 4);
	    			}
	  				buf1[i] = buf1[0x3f] = 0;
	  				buf2[j] = buf2[0x3f] = 0;
	  				for (k = 0; k < 0xf; k++)
	    			{
	      				int cnum = 0x10+0x10*k+0x100*j+0x1000*i;
	      				check (CALL(impl, buf1+i,buf2+j) == 0, cnum);
	      				buf1[i+k] = 'A' + i + k;
	      				buf1[i+k+1] = 0;
	      				check (CALL(impl, buf1+i,buf2+j) > 0, cnum+1);
	      				check (CALL(impl, buf2+j,buf1+i) < 0, cnum+2);
	      				buf2[j+k] = 'B' + i + k;
	      				buf2[j+k+1] = 0;
	      				check (CALL(impl, buf1+i,buf2+j) < 0, cnum+3);
	      				check (CALL(impl, buf2+j,buf1+i) > 0, cnum+4);
	      				buf2[j+k] = 'A' + i + k;
	      				buf1[i] = 'A' + i + 0x80;
	      				check (CALL(impl, buf1+i,buf2+j) > 0, cnum+5);
	      				check (CALL(impl, buf2+j,buf1+i) < 0, cnum+6);
	      				buf1[i] = 'A' + i;
	    			}
				}
  		}
	}
}

	int
test_main_strcmp (void *ft_strcmp)
{
	INIT();
	IMPL (ft_strcmp, 1);
  	size_t i;

  	test_init ();
  	check_strcmp();

	test_strcmp();

  	for (i = 1; i < 32; ++i)
    {
      	do_test (CHARBYTES * i, CHARBYTES * i, i, MIDCHAR, 0);
      	do_test (CHARBYTES * i, CHARBYTES * i, i, MIDCHAR, 1);
      	do_test (CHARBYTES * i, CHARBYTES * i, i, MIDCHAR, -1);
    }

  	for (i = 1; i < 10 + CHARBYTESLOG; ++i)
    {
      	do_test (0, 0, 2 << i, MIDCHAR, 0);
      	do_test (0, 0, 2 << i, LARGECHAR, 0);
      	do_test (0, 0, 2 << i, MIDCHAR, 1);
      	do_test (0, 0, 2 << i, LARGECHAR, 1);
      	do_test (0, 0, 2 << i, MIDCHAR, -1);
      	do_test (0, 0, 2 << i, LARGECHAR, -1);
      	do_test (0, CHARBYTES * i, 2 << i, MIDCHAR, 1);
      	do_test (CHARBYTES * i, CHARBYTES * (i + 1), 2 << i, LARGECHAR, 1);
    }

  	for (i = 1; i < 8; ++i)
    {
      	do_test (CHARBYTES * i, 2 * CHARBYTES * i, 8 << i, MIDCHAR, 0);
      	do_test (2 * CHARBYTES * i, CHARBYTES * i, 8 << i, LARGECHAR, 0);
      	do_test (CHARBYTES * i, 2 * CHARBYTES * i, 8 << i, MIDCHAR, 1);
      	do_test (2 * CHARBYTES * i, CHARBYTES * i, 8 << i, LARGECHAR, 1);
      	do_test (CHARBYTES * i, 2 * CHARBYTES * i, 8 << i, MIDCHAR, -1);
      	do_test (2 * CHARBYTES * i, CHARBYTES * i, 8 << i, LARGECHAR, -1);
    }

  	do_random_tests ();
  	return ret;
}
