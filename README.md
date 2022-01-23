# 実装アルゴリズム一覧

## 基礎（basic/）
### 組み合わせの漸化式（combi/）

<img src="https://user-images.githubusercontent.com/65803919/150450882-fd2ad717-cf44-41df-9797-151dd6585a2b.png"> を以下の漸化式で求める.

<img src="https://user-images.githubusercontent.com/65803919/150450933-4349a3e8-700e-4011-b99e-c97b3d8d2d59.png">

### Hornerの方法（horner/）

<img src="https://user-images.githubusercontent.com/65803919/150663572-230d53aa-496c-4cbf-ba1a-10931b5e70ae.png" style="height: 22px; width: auto;">

以上の式は以下の式で記述できる

<img src="https://user-images.githubusercontent.com/65803919/150663589-faeecf1a-ffc0-4f38-a1e3-61c2077b537a.png" style="height: 20px; width: auto;">

## データ構造（data_structure/）
### 双方向リスト（list/）

## ソート（sort/）
### バブルソート（bubble/）
### クイックソート（quick/）
### 単純挿入ソート（insert/）
### シェルソート（shell/）
gapの間隔で配列の要素を抜き出してその配列をソートする. 
ソートが終わったら徐々にgapを狭めていく. 

gapの求め方は以下の漸化式で, <img src="https://user-images.githubusercontent.com/65803919/150663645-36ae606e-bc53-49f1-b67d-e67e88610ab8.png" style="height: 12px; width: auto;"> が配列サイズを超えないように調整する.

<img src="https://user-images.githubusercontent.com/65803919/150663643-d775568f-705e-4ea5-860e-3eb1e8defa9a.png" style="height: 16px; width: auto;">
<br>
<img src="https://user-images.githubusercontent.com/65803919/150663644-6bddfc00-c059-4e7b-b4a4-445105c302ff.png" style="height: 17px; width: auto;">
<br>
<br>

例えば配列サイズが5のときは <img src="https://user-images.githubusercontent.com/65803919/150663645-36ae606e-bc53-49f1-b67d-e67e88610ab8.png" style="height: 12px; width: auto;"> が4になる.

## 探索（search/）
### 二分探索（binary/）
