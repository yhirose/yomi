yomi
====

中国語ピンイン・日本語ルビ振りツール
(powered by [KyTea](http://www.phontron.com/kytea/index-ja.html))

## 実行環境の準備 (Mac OS X) 

### KyTeaのインストール

KyTeaはHomebrewからインストールできます。

    brew install kytea

### clangのインストール 

このツールは，clang++を使用してビルドします。clang++はXCodeのCommand Line Toolsに含まれていますす。まずApp StoreからXCodeをインストールし，続いて【Xcode】→【Preference】→【Download】メーニューからCommand Line Toolsをインストールします。`brew install llvm`でもインストールできます。

### yomi 実行ファイルのビルド

読み付与実行ファイルをビルドします。scriptディレクトリにMakefileがあります。

    cd scripts/
    make

### nokogiri gem ライブラリのインストール

Rubyスクリプト内でnokogiriライブラリを使用します。Ruby Gemからインストールして下さい。

    gem install nokogiri

## モデルの作成

### コーパスの準備

corpusディレクトリの直下に，コーパスファイルを作成してください。複数ファイルでもOKです。フォーマットは以下の通りです。

    {本日|ほんじつ}は{晴天|せいてん}なり。

縦棒で区切られた単語と読みを，波括弧で括ります。

### 辞書の準備

dictディレクトリの直下に，任意の名前の辞書ファイルを作成してください。決して1つ以上のファイルを置かないで下さい。フォーマットは以下の通りです。

    我们/wo3\ men5

スラッシュで区切られた左側が単語，右側が読みになります。例のように，読みにスペースを入れたい時はバックスラッシュでエスケープしてください。

### モデルの作成

以下のコマンドを実行すると，yomi.modelファイルが作成されます。

    ./mkmodel

## 読みの付与

### HTML出力

標準入力からHTMLを読み込み，`<ruby>`タグ付きHTMLフォーマットで標準出力へ。

    ./mkhtml

### コーパス出力

標準入力からHTMLを読み込み，コーパスフォーマットで標準出力へ。このファイルを校正し，モデル作成用コーパスに追加することにより，精度を向上させることができます。

    ./mkcorpus
