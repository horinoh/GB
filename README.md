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