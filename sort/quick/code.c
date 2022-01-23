#include <stdio.h>
#include <stdbool.h>

#include "../../helpers/base.h"
#include "../../helpers/ary.h"

// 要素番号を要素の値を基準にバブルソート
void bubbleSortIdx(int idxes[], int ary[], int bottom, int top) {
    // 左側から1個, 2個, 3個...というようにソートしていく
    for (int i = bottom; i <= top; i++) {
        // iより左側はソート済なので, iより右側の要素と比較してソートする
        // 後ろから前へソートするとほしい値が前の方に来る
        for (int j = top; j > i; j--) {
            if (ary[i] > ary[j]) {
                swap(&idxes[i], &idxes[j]);
                swap(&ary[i], &ary[j]);
            }
        }
    }
}

/*  処理Ⅱ ... 基準値を決定する
    [事前条件]
    ・配列の要素数が3個以上であること

    [事後条件]
    ・基準値が両端, 中央の要素の中央値であること

    [手順]
    (1) 左端, 中央, 右端の順に要素番号を格納した配列(=idx), 左端, 中央, 右端の順に要素の値を格納した配列(=base)を定義
    (2) idxをbaseを利用してソートする. (今回はバブルソートを利用)
    (3) ソート後のidxの1番目の要素を返す.
        ※idxの1番目の要素が中央値の要素の要素番号となる
*/
int definebaseIdx(int ary[], int bottom, int top) {
    // (1) 左端, 中央, 右端の順に要素番号を格納した配列(=idx), 左端, 中央, 右端の順に要素の値を格納した配列(=base)を定義
    int idxes[3] = {bottom, (bottom + top) / 2, top};
    int bases[3] = {ary[idxes[0]], ary[idxes[1]], ary[idxes[2]]};

    // (2) idxをbaseを利用してソートする. (今回はバブルソートを利用)
    bubbleSortIdx(idxes, bases, 0, 2);

    // (3) ソート後のidxの1番目の要素を返す.
    return idxes[1];
}

/*   処理Ⅲ ... 基準値未満の要素と基準値以上の要素に分割する
    [事前条件]
    ・配列の要素数が3個以上であること
    　　※要素数が1個以下の場合はソートしなくていい
        ※要素数が2個以下の場合は手順(3)でうまくいかない
        　例えば[0, 2]の場合, 基準値は[0, 0, 2]の中央値なので0番目の要素の0となり, 
        　　(1)0番目の要素と1番目の要素を交換するので, [2, 0]となる.
            (2)1番目の要素は探索対象でなく探索対象が0番目の要素のみなので配列は変化しない.
            (3)0番目の要素と1番目の要素を交換するので, [2, 0]となる. これは事後条件と一致しない.

    [事後条件]
    ・基準要素の値が基準値であること
    ・基準要素より左側の要素の値がすべて基準値未満であること
    ・基準要素より右側の要素の値がすべて基準値以上であること

    [手順]
    (1) 基準値の要素と末尾を交換

    (2) 末尾以外の配列で, 左側は基準値未満の値, 右側は基準値以上の値になるようにする.
        基本的には左側から基準値未満でない(=基準値以上の)値, 左側から基準値以上でない(=基準値未満の)値を探して, その2値を交換していく.
        詳細な手順を示す.
        　※左側の探索変数をlower, 右側の探索変数をupperとする.
        　※①, ②でlower=upperとなったら探索終了であり, (3)に行く
        ①末尾以外の配列を左側から探索して, 基準値以上の値となる要素が見つかるまでlowerを増やす. 
        ②末尾以外の配列を右側から探索し, 基準値未満の値となる要素が見つかるまでupperを減らす.
        ③要素番号=lowerの要素(=基準値以上の要素)と要素番号=upperの要素(=基準値未満の要素)を交換する

    (3) 基準値以上の値群の一番左側の要素(基準要素とする)と末尾を交換
        ※この時点でlower=upperとなっている
*/
int dividearyByBase(int ary[], int bottom, int top, int base_idx, int base) {
    int lower, upper;

    // (1) 基準値の要素と末尾を交換
    swap(&ary[base_idx], &ary[top]);

    // (2) 末尾以外の配列で, 左側は基準値未満の値, 右側は基準値以上の値になるようにする
    for (lower = bottom, upper = top - 1;;) {
        bool is_search_completed = false;   // 探索完了かどうか

        // ①末尾以外の配列を左側から探索して, 基準値以上の値となる要素が見つかるまでlowerを増やす. 
        while(true) {
            if (lower == upper) {
                is_search_completed = true;
                break;
            }
            if (ary[lower] >= base) break;
            lower++;
        }
        if (is_search_completed) break; // 探索完了の場合

        // ②末尾以外の配列を右側から探索し, 基準値未満の値となる要素が見つかるまでupperを減らす.
        while(true) {
            if (lower == upper) {
                is_search_completed = true;
                break;
            }
            if (ary[upper] < base) break;
            upper--;
        }
        if (is_search_completed) break; // 探索完了の場合
            
        // ③要素番号=lowerの要素(=基準値以上の要素)と要素番号=upperの要素(=基準値未満の要素)を交換する
        swap(&ary[lower], &ary[upper]);
    }
    
    // (3) 基準値以上の値群の一番左側の要素(基準要素とする)と末尾を交換
    int base_enum_idx = upper;  // 基準要素の要素番号
    swap(&ary[top], &ary[base_enum_idx]);

    return base_enum_idx;
}

/*  処理Ⅰ ... 昇順にクイックソートを行う
    [事前条件]
    なし

    [事後条件]
    ・昇順にソートされていること

    [手順]
    (1) 配列サイズが1個の場合はソートしない
    (2) 配列サイズが2個の場合は処理Ⅱでうまく行かないので, 2値の大小を比較してソートする
    (3) 基準値を決定する(処理Ⅱ)
    (4) 基準値未満の要素と基準値以上の要素に分割する(処理Ⅲ)
    (5) 基準要素より左側の配列と基準要素より右側の配列をさらにソートする(再帰関数)
*/
void quickSort(int ary[], int bottom, int top) {
    // (1) 配列サイズが1個の場合はソートしない
    if ((top + 1) - bottom <= 1) return;

    // (2) 配列サイズが2個の場合は処理Ⅱでうまく行かないので, 2値の大小を比較してソートする
    if ((top + 1) - bottom  == 2) {
        if (ary[bottom] > ary[top]) 
            swap(&ary[bottom], &ary[top]);
        return;
    }

    // (3) 基準値を決定する(処理Ⅱ)
    int base_idx = definebaseIdx(ary, bottom, top);
    int base = ary[base_idx];
    // (4) 基準値未満の要素と基準値以上の要素に分割する(処理Ⅲ)
    int base_enum_idx = dividearyByBase(ary, bottom, top, base_idx, base);

    // (5) 基準要素より左側の配列と基準要素より右側の配列をさらにソートする(再帰関数)
    quickSort(ary, bottom, base_enum_idx - 1);
    quickSort(ary, base_enum_idx + 1, top);
}

#define N 6
int main(int argc, char const *argv[])
{
    srandom(time(NULL));

    int ary[N];
    initAryByRandom(ary, 0, N - 1, 0, 99);
    
    printf("ソート前　");
    printAry(ary, 0, N - 1);
    printf("\n");
    
    quickSort(ary, 0, N - 1);

    printf("\nソート後　");
    printAry(ary, 0, N - 1);
    printf("\n");

    return 0;
}
