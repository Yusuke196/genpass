# 概要

UNIXで動くパスワード生成コマンドをC++で作成する。

コマンド名はgenerate passwordの略でgpとする。

引数は以下。

length: 桁数。デフォルトは16
digit: 含める数値の数。デフォルトは4
symbol: 含める記号の数。デフォルトは0

# 背景

パスワードマネージャとして1Passwordを使っており、そこにパスワード生成の機能はついているが、適当なパスワードを生成するためにいちいち1Passwordを開くのは面倒だった。

# ログ

引数名を決めるにあたっては、1 Passwordのインターフェイスを参考にした。
[![Image from Gyazo](https://i.gyazo.com/7267f2bad8698a2043f72c7b20143906.png)](https://gyazo.com/7267f2bad8698a2043f72c7b20143906)

PATHにプログラムを登録する方法については、以下を参照。この作業にあたって、~/.local/binディレクトリを作成した。
https://lecture.ecc.u-tokyo.ac.jp/~hideo-t/tutorials/write_a_command_in_cpp.html#path-make-it-usable-via-path

これをターミナルから呼び出すためには、
```
PATH=$PATH:~/.local/bin
```
とする。さらに、永続的に使えるようにするためには、この命令をbash_profileなどに書き込む必要がある。
