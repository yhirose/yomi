yomi
====

中国語ピンイン・日本語ルビ振りツール
(powered by [KyTea](http://www.phontron.com/kytea/index-ja.html))

## 実行環境の準備 (Mac OS X) 

### XCodeのインストール 

このツールは，clang++でビルドされます。clang++は最新のXCodeに含まれていますので，App Storeからインストールして下さい。

### KyTeaのインストール

    brew install kytea

### nokogiri gem ライブラリのインストール

    gem install nokogiri

### yomi 実行ファイルのビルド

    cd scripts/
    make

## モデルの作成

### コーパスの準備

`corpus`ディレクトリの直下に，コーパスファイルを作成してください。フォーマットは以下の通りです。

### 辞書の準備

`dict`ディレクトリの直下に，辞書ファイルを作成してください。フォーマットは以下の通りです。

### モデル作成コマンドの実行

以下のコマンドを実行すると，yomi.modelファイルが作成されます。

    ./mkmodel

## 読み付与の実行

### 標準入力からHTMLを読み込み，`<ruby>`タグ付きHTMLフォーマットで標準出力へ

    ./mkhtml < [STDIN] > [STDOUT]

### 標準入力からHTMLを読み込み，コーパスフォーマットで標準出力へ

    ./mkcorpus < [STDIN] > [STDOUT]
