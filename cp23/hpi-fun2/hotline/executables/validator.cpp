#include <testlib.h>
#include <bits/stdc++.h>

using namespace std;

bool dd(int k) {
	vector<bool> o(10, false);
	while (k > 0) {
		int digit = k % 10;
		if (o[digit]) return false;
		o[digit] = true;
		k = (k - digit) / 10;
	}
	return true;
}

int main(int argc, char* argv[]) {
    setName("describe your validator here");
    registerTestlibCmd(argc, argv);

    // Use inf (.in file), ouf (submission output) and ans (.ans file)
    // Use quit(_wa, message) or quitf(_wa, format_string, args...) to report wrong answers
    // Exchange _wa by _pe if the format is wrong (should mostly be taken care of by the
    // input functions of ouf)

	int l, r;
	l = inf.readInt();
	r = inf.readInt();

	int x = ouf.readInt();

	// out is impossible
	if (x == -1) {
		int mx = ans.readInt();
		if (mx == -1) goto ok;
		else quit(_wa, "wrong impossible");
	}

	// check bounds
	if (!(l <= x && x <= r))
		quit(_wa, "bounds not met");

	// check for double digits
	if (!dd(x)) quit(_wa, "output has doubled digits");

ok:
    quit(_ok, "");
}
