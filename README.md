# GB

## ビルド
- [GBDK-2020](https://github.com/gbdk-2020/gbdk-2020)
    - Windows をクリックして DL、解凍して gbdk を Cドライブ直下に配置
    - C:\gbdk\bin を環境変数 Path に通しておく
    - ビルド
        ~~~
        $lcc -Wa-l -Wl-m -Wl-j -o XXX.gb XXX.c
        ~~~
    - サンプルは gbdk/examples 以下

## 実行
- [エミュレータ(mGBA)](https://mgba.io/)
    - C:\mGBA-0.9.3-win32 を環境変数 Path に通しておく
        ~~~
        $mGBA XXX.gb
        ~~~
        
- 初期設定のキー配置
    - 方向 = Arrow Key
    - B, A = Z, X
    - セレクト, スタート = BackSpace, Return
    - L, R = A, S

## VS Code からのビルド、実行
 - ファイル - フォルダを開く で対象のフォルダを開く
 - ターミナル - タスクの構成 - テンプレートから tasks.json を生成 - Others - tasks.json を編集する
    ~~~
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Build GB",
            "type": "shell",
            "command": "lcc -Wa-l -Wl-m -Wl-j -o main.gb main.c"
        },
        {
            "label": "Execute GB",
            "type": "shell",
            "command": "mGBA main.gb"
        },
        {
            "label": "Build and execute GB",
            "type": "shell",
            "dependsOrder": "sequence",
            "dependsOn": [
                "Build GB",
                "Execute GB"
            ]
        },
    ]
    ~~~
 - ターミナル - タスクの実行 - 上記で作成したタスク名("Build GB"等)を選択して実行

<!--
表示範囲 
    160x144 (20x18セル)

BG 
    256x256 (32x32セル)

Window 
    256x256 (32x32セル)
    RBに接した状態でしか配置できない (LTには配置できない)

スプライト
    8x8 or 8x16
    最大 40 表示

パレット
    BG/Window用 x1
    スプライト用 x2

タイル(パターン)
    最大 384
        BG/Window              [0, 127]
        BG/Window, スプライト   [128, 255]
        スプライト              [0, 127]
-->