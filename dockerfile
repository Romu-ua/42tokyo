# ベースイメージとしてUbuntuを指定
FROM ubuntu:22.04

# 必要な環境変数を設定（対話型プロンプトを無効化）
ENV DEBIAN_FRONTEND=noninteractive

# 必要なパッケージをインストール
RUN apt-get update && \
    apt-get install -y \
        clang \
        valgrind \
        git \
        make \
        g++ \
        ncurses-bin \
        build-essential \
        man \
        manpages \
        man-db && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# 作業ディレクトリを指定
WORKDIR /workspace

# ホストのファイルをコンテナにコピー
COPY . .

# シェルをBashに設定
SHELL ["/bin/bash", "-c"]

# エントリーポイント
CMD ["bash"]
