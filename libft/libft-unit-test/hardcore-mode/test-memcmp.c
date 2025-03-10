#include "utils.h"
# define MEMCMP memcmp
# define MEMCPY memcpy
# define SIMPLE_MEMCMP memcmp
# define CHAR char
# define MAX_CHAR 255
# define UCHAR unsigned char
# define CHARBYTES 1
# define CHAR__MIN CHAR_MIN
# define CHAR__MAX CHAR_MAX

typedef int (*proto_t) (const CHAR *, const CHAR *, size_t);

	static int
check_result (impl_t *impl, const CHAR *s1, const CHAR *s2, size_t len,
	    int exp_result)
{
  	int result = CALL (impl, s1, s2, len);
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
do_one_test (impl_t *impl, const CHAR *s1, const CHAR *s2, size_t len,
	    int exp_result)
{
  	if (check_result (impl, s1, s2, len, exp_result) < 0)
    	return;
}

	static void
do_test (size_t align1, size_t align2, size_t len, int exp_result)
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

  	s1 = (CHAR *) (buf1 + align1);
  	s2 = (CHAR *) (buf2 + align2);

  	for (i = 0; i < len; i++)
    	s1[i] = s2[i] = 1 + (23 << ((CHARBYTES - 1) * 8)) * i % CHAR__MAX;

  	s1[len] = align1;
  	s2[len] = align2;
  	s2[len - 1] -= exp_result;

  	FOR_EACH_IMPL (impl, 0)
    	do_one_test (impl, s1, s2, len, exp_result);
}

	static void
do_random_tests (void)
{
  	size_t i, j, n, align1, align2, pos, len;
  	int result;
  	long r;
  	UCHAR *p1 =  (UCHAR *) (buf1 + page_size - 512 * CHARBYTES);
  	UCHAR *p2 =  (UCHAR *) (buf2 + page_size - 512 * CHARBYTES);

  	for (n = 0; n < ITERATIONS; n++)
    {
   		align1 = random () & 31;
      	if (random () & 1)
			align2 = random () & 31;
      	else
			align2 = align1 + (random () & 24);
      	pos = random () & 511;
      	j = align1;
      	if (align2 > j)
			j = align2;
      	if (pos + j >= 512)
			pos = 511 - j - (random () & 7);
      	len = random () & 511;
      	if (len + j >= 512)
			len = 511 - j - (random () & 7);
      	j = len + align1 + 64;
      	if (j > 512) j = 512;
      	for (i = 0; i < j; ++i)
			p1[i] = random () & 255;
      	for (i = 0; i < j; ++i)
			p2[i] = random () & 255;

      	result = 0;
      	if (pos >= len)
			MEMCPY ((CHAR *) p2 + align2, (const CHAR *) p1 + align1, len);
      	else
		{
	  		MEMCPY ((CHAR *) p2 + align2, (const CHAR *) p1 + align1, pos);
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

      	FOR_EACH_IMPL (impl, 1)
		{
	  		r = CALL (impl, (CHAR *) p1 + align1, (const CHAR *) p2 + align2,
		    		len);
	  		if ((r == 0 && result)
	      			|| (r < 0 && result >= 0)
	      			|| (r > 0 && result <= 0))
	    	{
	      		error (0, 0, "Iteration %zd - wrong result in function %s (%zd, %zd, %zd, %zd) %ld != %d, p1 %p p2 %p",
		     			n, impl->name, align1 * CHARBYTES & 63,  align2 * CHARBYTES & 63, len, pos, r, result, p1, p2);
	      		ret = 1;
	    	}
		}
    }
}

	static void
check1 (void)
{
  	CHAR s1[116], s2[116];
  	int n, exp_result;

  	s1[0] = -108;
  	s2[0] = -108;
  	s1[1] = 99;
  	s2[1] = 99;
  	s1[2] = -113;
  	s2[2] = -113;
  	s1[3] = 1;
  	s2[3] = 1;
  	s1[4] = 116;
  	s2[4] = 116;
  	s1[5] = 99;
  	s2[5] = 99;
  	s1[6] = -113;
  	s2[6] = -113;
  	s1[7] = 1;
  	s2[7] = 1;
  	s1[8] = 84;
  	s2[8] = 84;
  	s1[9] = 99;
  	s2[9] = 99;
  	s1[10] = -113;
  	s2[10] = -113;
  	s1[11] = 1;
  	s2[11] = 1;
  	s1[12] = 52;
  	s2[12] = 52;
  	s1[13] = 99;
  	s2[13] = 99;
  	s1[14] = -113;
  	s2[14] = -113;
  	s1[15] = 1;
  	s2[15] = 1;
  	s1[16] = -76;
  	s2[16] = -76;
  	s1[17] = -14;
  	s2[17] = -14;
  	s1[18] = -109;
  	s2[18] = -109;
  	s1[19] = 1;
  	s2[19] = 1;
  	s1[20] = -108;
  	s2[20] = -108;
  	s1[21] = -14;
  	s2[21] = -14;
  	s1[22] = -109;
  	s2[22] = -109;
  	s1[23] = 1;
  	s2[23] = 1;
  	s1[24] = 84;
  	s2[24] = 84;
  	s1[25] = -15;
  	s2[25] = -15;
  	s1[26] = -109;
  	s2[26] = -109;
  	s1[27] = 1;
  	s2[27] = 1;
  	s1[28] = 52;
  	s2[28] = 52;
  	s1[29] = -15;
  	s2[29] = -15;
  	s1[30] = -109;
  	s2[30] = -109;
  	s1[31] = 1;
  	s2[31] = 1;
  	s1[32] = 20;
  	s2[32] = 20;
  	s1[33] = -15;
  	s2[33] = -15;
  	s1[34] = -109;
  	s2[34] = -109;
  	s1[35] = 1;
  	s2[35] = 1;
  	s1[36] = 20;
  	s2[36] = 20;
  	s1[37] = -14;
  	s2[37] = -14;
  	s1[38] = -109;
  	s2[38] = -109;
  	s1[39] = 1;
  	s2[39] = 1;
  	s1[40] = 52;
  	s2[40] = 52;
  	s1[41] = -14;
  	s2[41] = -14;
  	s1[42] = -109;
  	s2[42] = -109;
  	s1[43] = 1;
  	s2[43] = 1;
  	s1[44] = 84;
  	s2[44] = 84;
  	s1[45] = -14;
  	s2[45] = -14;
  	s1[46] = -109;
  	s2[46] = -109;
  	s1[47] = 1;
  	s2[47] = 1;
  	s1[48] = 116;
  	s2[48] = 116;
  	s1[49] = -14;
  	s2[49] = -14;
  	s1[50] = -109;
  	s2[50] = -109;
  	s1[51] = 1;
  	s2[51] = 1;
  	s1[52] = 116;
  	s2[52] = 116;
  	s1[53] = -15;
  	s2[53] = -15;
  	s1[54] = -109;
  	s2[54] = -109;
  	s1[55] = 1;
  	s2[55] = 1;
  	s1[56] = -44;
  	s2[56] = -44;
  	s1[57] = -14;
  	s2[57] = -14;
  	s1[58] = -109;
  	s2[58] = -109;
  	s1[59] = 1;
  	s2[59] = 1;
  	s1[60] = -108;
  	s2[60] = -108;
  	s1[61] = -15;
  	s2[61] = -15;
  	s1[62] = -109;
  	s2[62] = -109;
  	s1[63] = 1;
  	s2[63] = 1;
  	s1[64] = -76;
  	s2[64] = -76;
  	s1[65] = -15;
  	s2[65] = -15;
  	s1[66] = -109;
  	s2[66] = -109;
  	s1[67] = 1;
  	s2[67] = 1;
  	s1[68] = -44;
  	s2[68] = -44;
  	s1[69] = -15;
  	s2[69] = -15;
  	s1[70] = -109;
  	s2[70] = -109;
  	s1[71] = 1;
  	s2[71] = 1;
  	s1[72] = -12;
  	s2[72] = -12;
  	s1[73] = -15;
  	s2[73] = -15;
  	s1[74] = -109;
  	s2[74] = -109;
  	s1[75] = 1;
  	s2[75] = 1;
  	s1[76] = -12;
  	s2[76] = -12;
  	s1[77] = -14;
  	s2[77] = -14;
  	s1[78] = -109;
  	s2[78] = -109;
  	s1[79] = 1;
  	s2[79] = 1;
  	s1[80] = 20;
  	s2[80] = -68;
  	s1[81] = -12;
  	s2[81] = 64;
  	s1[82] = -109;
  	s2[82] = -106;
  	s1[83] = 1;
  	s2[83] = 1;
  	s1[84] = -12;
  	s2[84] = -12;
  	s1[85] = -13;
  	s2[85] = -13;
  	s1[86] = -109;
  	s2[86] = -109;
  	s1[87] = 1;
  	s2[87] = 1;
  	s1[88] = -44;
  	s2[88] = -44;
  	s1[89] = -13;
  	s2[89] = -13;
  	s1[90] = -109;
  	s2[90] = -109;
  	s1[91] = 1;
  	s2[91] = 1;
  	s1[92] = -76;
  	s2[92] = -76;
  	s1[93] = -13;
  	s2[93] = -13;
  	s1[94] = -109;
  	s2[94] = -109;
  	s1[95] = 1;
  	s2[95] = 1;
  	s1[96] = -108;
  	s2[96] = -108;
  	s1[97] = -13;
  	s2[97] = -13;
  	s1[98] = -109;
  	s2[98] = -109;
  	s1[99] = 1;
  	s2[99] = 1;
  	s1[100] = 116;
  	s2[100] = 116;
  	s1[101] = CHAR__MIN;
  	s2[101] = CHAR__MAX;
  	s1[102] = -109;
  	s2[102] = -109;
  	s1[103] = 1;
  	s2[103] = 1;
  	s1[104] = 84;
  	s2[104] = 84;
  	s1[105] = -13;
  	s2[105] = -13;
  	s1[106] = -109;
  	s2[106] = -109;
  	s1[107] = 1;
  	s2[107] = 1;
  	s1[108] = 52;
  	s2[108] = 52;
  	s1[109] = -13;
  	s2[109] = -13;
  	s1[110] = -109;
  	s2[110] = -109;
  	s1[111] = 1;
  	s2[111] = 1;
  	s1[112] = CHAR__MAX;
  	s2[112] = CHAR__MIN;
  	s1[113] = -13;
  	s2[113] = -13;
  	s1[114] = -109;
  	s2[114] = -109;
  	s1[115] = 1;
  	s2[115] = 1;

  	n = 116;
  	for (int i = 0; i < n; i++)
    {
      	exp_result = SIMPLE_MEMCMP (s1 + i, s2 + i, n - i);
      	FOR_EACH_IMPL (impl, 0)
			check_result (impl, s1 + i, s2 + i, n - i, exp_result);
    }
}

static void
test_memcmp (void *ft_memcmp)
{
	typeof(memcmp) *mm = (typeof(memcmp) *)ft_memcmp;
  int cnt = 1;
  char one[21];
  char two[21];

  it = "ft_memcmp";
  check(mm("a", "a", 1) == 0, cnt++);	/* Identity. */
  check(mm("abc", "abc", 3) == 0, cnt++);	/* Multicharacter. */
  check(mm("abcd", "abcf", 4) < 0, cnt++);	/* Honestly unequal. */
  check(mm("abcf", "abcd", 4) > 0, cnt++);
  check(mm("alph", "cold", 4) < 0, cnt++);
  check(mm("a\203", "a\003", 2) > 0, cnt++);
  check(mm("a\003", "a\203", 2) < 0, cnt++);
  check(mm("a\003bc", "a\203bc", 2) < 0, cnt++);
  check(mm("abc\203", "abc\003", 4) > 0, cnt++);
  check(mm("abc\003", "abc\203", 4) < 0, cnt++);
  check(mm("abcf", "abcd", 3) == 0, cnt++);	/* Count limited. */
  check(mm("abc", "def", 0) == 0, cnt++);	/* Zero count. */
  /* Comparisons with shifting 4-byte boundaries. */
  for (int i = 0; i < 4; ++i)
    {
      char *a = one + i;
      char *b = two + i;
      strncpy(a, "--------11112222", 16);
      strncpy(b, "--------33334444", 16);
      check(mm(b, a, 16) > 0, cnt++);
      check(mm(a, b, 16) < 0, cnt++);
    }
}

	int
test_main_memcmp (void *ft_memcmp)
{
	INIT();
  	size_t i;

  	test_init ();

	IMPL (ft_memcmp, 1);

	test_memcmp(ft_memcmp);

  	check1 ();

  	for (i = 1; i < 16; ++i)
    {
      	do_test (i * CHARBYTES, i * CHARBYTES, i, 0);
      	do_test (i * CHARBYTES, i * CHARBYTES, i, 1);
      	do_test (i * CHARBYTES, i * CHARBYTES, i, -1);
    }

  	for (i = 0; i < 16; ++i)
    {
      	do_test (0, 0, i, 0);
      	do_test (0, 0, i, 1);
      	do_test (0, 0, i, -1);
    }

  	for (i = 1; i < 10; ++i)
    {
      	do_test (0, 0, 2 << i, 0);
      	do_test (0, 0, 2 << i, 1);
      	do_test (0, 0, 2 << i, -1);
      	do_test (0, 0, 16 << i, 0);
      	do_test ((8 - i) * CHARBYTES, (2 * i) * CHARBYTES, 16 << i, 0);
      	do_test (0, 0, 16 << i, 1);
      	do_test (0, 0, 16 << i, -1);
    }

  	for (i = 1; i < 8; ++i)
    {
      	do_test (i * CHARBYTES, 2 * (i * CHARBYTES), 8 << i, 0);
      	do_test (i * CHARBYTES, 2 * (i * CHARBYTES), 8 << i, 1);
      	do_test (i * CHARBYTES, 2 * (i * CHARBYTES), 8 << i, -1);
    }

  	do_random_tests ();
  	return ret;
}
