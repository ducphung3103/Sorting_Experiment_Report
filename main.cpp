/*
    Created by: DeruckPhung
    University Of Information Technology - VNUHCM
*/

#include <bits/stdc++.h>
#include <filesystem>
#include <chrono>

using namespace std;
using namespace std::chrono;

namespace fs = std::filesystem;


mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l, int r){
    return l + rd() % (r - l + 1);
}


// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")

#define ll long long 
#define pii pair<int, int>
#define pll pair<long long>
#define fi first 
#define se second
#define ALL(x) (x).begin(), (x).end()
#define BIT(x, i) (((x) >> (i)) & (1LL))
#define MASK(x) ((1LL) << (x))
#define CNTBIT(x) __builtin_popcount(x)
#define pb push_back

const int N = 1e6 + 5;
const int mod = 1e9 + 7;
const int INF = 1e9 + 7;

double a[N], b[N];
int n;

//* ===================== QuickSort ===================== */


int partition_lomuto(int l, int r) {
    int pivotIndex = Rand(l, r);
    swap(a[pivotIndex], a[r]);

    double pivot = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void quickSort(int l, int r) { 
    if (l >= r) return; 
    int p = partition_lomuto(l, r); 
    quickSort(l, p - 1); 
    quickSort(p + 1, r); 
}

void QuickSort(){
	for(int i = 0; i < n; i++) a[i] = b[i];

	auto start = high_resolution_clock::now();
	quickSort(0, n - 1);
	auto end = high_resolution_clock::now();
	double ms = duration<double, std::milli>(end - start).count();


	bool oke = true;
	for(int i = 1; i < n; i++) if(a[i - 1] > a[i]) oke = false;
	//for(int i = 1; i < n; i++) cout << b[i] << " ";
	
	cout << "QuickSort: " << oke << " " << (int) ms << endl;
}

/* ===================== HeapSort ===================== */
void heapify(int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest]) largest = left;
    if (right < n && a[right] > a[largest]) largest = right;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(n, largest);
    }
}

void heapSort(int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(i, 0);
    }
}

void HeapSort(){
    for(int i = 0; i < n; i++) a[i] = b[i];

	auto start = std::chrono::high_resolution_clock::now();
	heapSort(n);
	auto end = std::chrono::high_resolution_clock::now(); 
	double ms = duration<double, std::milli>(end - start).count();


	bool oke = true;
	for(int i = 1; i < n; i++) if(a[i - 1] > a[i]) oke = false;
	//for(int i = 1; i < n; i++) cout << b[i] << " ";
	
	cout << "HeapSort: " << oke << " " << (int) ms << endl;
}

/* ===================== MergeSort ===================== */
void merge_arr(int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    double* L = new double[n1];
    double* R = new double[n2];

    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int j = 0; j < n2; j++) R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(l, m);
    mergeSort(m + 1, r);
    merge_arr(l, m, r);
}

void MergeSort(){
	for(int i = 0; i < n; i++) a[i] = b[i];

	auto start = std::chrono::high_resolution_clock::now();
	mergeSort(0, n - 1);
	auto end = std::chrono::high_resolution_clock::now(); 
	double ms = duration<double, std::milli>(end - start).count();


	bool oke = true;
	for(int i = 1; i < n; i++) if(a[i - 1] > a[i]) oke = false;
	//for(int i = 1; i < n; i++) cout << b[i] << " ";
	
	cout << "MergeSort: " << oke << " " << (int) ms << endl;
}


/* ===================== CppSort ===================== */
void CppSort(){
	for(int i = 0; i < n; i++) a[i] = b[i];

	auto start = std::chrono::high_resolution_clock::now();
	sort(a, a + n);
	auto end = std::chrono::high_resolution_clock::now(); 
	double ms = duration<double, std::milli>(end - start).count();


	bool oke = true;
	for(int i = 1; i < n; i++) if(a[i - 1] > a[i]) oke = false;
	//for(int i = 1; i < n; i++) cout << b[i] << " ";
	
	cout << "CppSort: " << oke << " " << (int) ms << endl;
}

void Read(){
	
}

void Solve(){

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // #define TASK "main"
    // if(fopen(TASK".inp", "r")){
    //     freopen(TASK".inp", "r", stdin);
    //     freopen(TASK".out", "w", stdout);
    // }

    // int TEST = 1;
    // while(TEST--){
    //     Read();
    //     Solve();
    // }

    string dir = "TEST";
    vector<string> files;

    for(auto &p : fs::directory_iterator(dir)){
        // if(p.is_regular_file() && p.path().extension() == ".inp"){
        //     files.push_back(p.path().string());
        //     //cout << p.path().string() << "\n";
        // }

        ifstream cin(p.path().string());
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i], b[i] = a[i];
        
        cout << p.path().string() << endl;
        QuickSort();
        HeapSort();
        MergeSort();
        CppSort();

        cin.close();
        //break;
    }
}

/*

Mỗi file sẽ có 4 dòng output theo format: 
    <Thuật toán sort>: <Sort đúng (1) hay sai (0)> <Thời gian sort (đơn vị ms)> 

OUTPUT:

TEST\01_integer.inp
QuickSort: 1 122
HeapSort: 1 237
MergeSort: 1 180
CppSort: 1 65

TEST\02_integer.inp
QuickSort: 1 133
HeapSort: 1 236
MergeSort: 1 172
CppSort: 1 66

TEST\03_integer.inp
QuickSort: 1 134
HeapSort: 1 265
MergeSort: 1 185
CppSort: 1 75

TEST\04_integer.inp
QuickSort: 1 125
HeapSort: 1 245
MergeSort: 1 183
CppSort: 1 68

TEST\05_real.inp
QuickSort: 1 228
HeapSort: 1 395
MergeSort: 1 290
CppSort: 1 170

TEST\06_real.inp
QuickSort: 1 210
HeapSort: 1 376
MergeSort: 1 278
CppSort: 1 169

TEST\07_real.inp
QuickSort: 1 217
HeapSort: 1 377
MergeSort: 1 279
CppSort: 1 168

TEST\08_real.inp
QuickSort: 1 217
HeapSort: 1 371
MergeSort: 1 284
CppSort: 1 169

TEST\8_real.inp
QuickSort: 1 207
HeapSort: 1 515
MergeSort: 1 316
CppSort: 1 168

TEST\greater_real.inp
QuickSort: 1 149
HeapSort: 1 235
MergeSort: 1 177
CppSort: 1 48

TEST\smaller_integer.inp
QuickSort: 1 135
HeapSort: 1 243
MergeSort: 1 184
CppSort: 1 70
*/