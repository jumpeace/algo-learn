# 実装アルゴリズム一覧

## 再帰（recursive/）
### 組み合わせの漸化式（combi/）

<img src="https://user-images.githubusercontent.com/65803919/150450882-fd2ad717-cf44-41df-9797-151dd6585a2b.png"> を以下の漸化式で求める.

<img src="https://user-images.githubusercontent.com/65803919/150450933-4349a3e8-700e-4011-b99e-c97b3d8d2d59.png">

### Hornerの方法（horner/）

<img src="https://user-images.githubusercontent.com/65803919/150663572-230d53aa-496c-4cbf-ba1a-10931b5e70ae.png" style="height: 22px; width: auto;">

以上の式は以下の式で記述できる

<img src="https://user-images.githubusercontent.com/65803919/150663589-faeecf1a-ffc0-4f38-a1e3-61c2077b537a.png" style="height: 20px; width: auto;">

### 階乗（factorial）
### フィボナッチ数（fibonacci）
### 迷路の出口探索（maze_exit）

## データ構造（data/）
### 双方向リスト（list/）
### 二分探索木（binary_tree/）
### ハッシュ値を求める（hash/）
※my_hash.cは自己流のハッシュ値です. ハッシュ値の元, 文字列の長さによって偏りが出ないようにしました.

## ソート（sort/）
### バブルソート（bubble/）
### クイックソート（quick/）
### 単純挿入ソート（insert/）
### シェルソート（shell/）
gapの間隔で配列の要素を抜き出してその配列をソートする. 
ソートが終わったら徐々にgapを狭めていく. 

gapの求め方は以下の漸化式で, <img src="https://user-images.githubusercontent.com/65803919/150663645-36ae606e-bc53-49f1-b67d-e67e88610ab8.png" style="height: 12px; width: auto;"> が配列サイズを超えないように調整する.

<img src="https://user-images.githubusercontent.com/65803919/150663956-25fa1620-2c8f-4358-bec0-2ccd60569fd7.png" style="height: 72px; width: auto;">
<br>
例えば配列サイズが5のときは<span><img src="https://user-images.githubusercontent.com/65803919/150663645-36ae606e-bc53-49f1-b67d-e67e88610ab8.png" style="height: 12px; width: auto;"></span>が4になる.


## 探索（search/）
### 二分探索（binary/）
