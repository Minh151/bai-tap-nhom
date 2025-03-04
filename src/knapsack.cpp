#include <iostream>
using namespace std;
int knapsack(int N, int w[], int v[], int W);
void itemsSelected(int N, int w[], int v[], int W, bool selected[]);
int main() {
	int N, W;
	cout << "Enter the number of items: ";
	cin >> N;
	cout << "Enter the max capacity: ";
	cin >> W;
	int v[N], w[N];
	cout << "Enter the weight and value of each item: \n";
	for (int i=0; i<N; i++) {
		cin >> w[i] >> v[i];
	}
	cout << "The max value possible is " << knapsack(N, w, v, W) << endl;
	bool selected[N] = {false};
	itemsSelected(N, w, v, W, selected);
	cout << "Items that were selected: ";
	for (int i=0; i<N; i++) {
		if (selected[i]) {
			cout << i+1 << " ";
		}
	}
	return 0;
}

int knapsack(int N, int w[], int v[], int W) {
	if (N==0 || W ==0) {
		return 0;
	}
	if (w[N-1]>W) {
		return knapsack (N-1, w, v, W);
	}
	int include = v[N-1] + knapsack (N-1, w, v, W-w[N-1]);
	int exclude = knapsack (N-1, w, v, W);
	return max(include, exclude);
}

void itemsSelected(int N, int w[], int v[], int W, bool selected[]) {
	if (N==0 || W==0) return;
	if (w[N-1]>W) {
		itemsSelected(N-1, w, v, W, selected);
	}
	else {
		int include = v[N-1] + knapsack(N-1, w, v, W-w[N-1]);
		int exclude = knapsack(N-1, w, v, W);
		if (include > exclude) {
			selected[N-1] = true;
			itemsSelected (N-1, w, v, W-w[N-1], selected);
		}
		else {
			itemsSelected (N-1, w, v, W, selected);
		}
	}
}
