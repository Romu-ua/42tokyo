# ベースイメージとしてUbuntuを指定
FROM ubuntu:22.04

# 必要な環境変数を設定（対話型プロンプトを無効化）
ENV DEBIAN_FRONTEND=noninteractive

# manコマンドおよび関連パッケージをインストール
RUN apt-get update && \
    apt-get install -y \
    man \
    manpages \
    man-db \
    less && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# 作業ディレクトリを指定
WORKDIR /app

# ホストのファイルをコンテナにコピー
COPY . .

# 必要に応じてスクリプトを実行
RUN chmod +x ./setup.sh && ./setup.sh

# エントリーポイント
CMD ["bash"]
