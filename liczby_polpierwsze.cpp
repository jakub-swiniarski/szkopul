// https://szkopul.edu.pl/problemset/problem/lpp/site/

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

inline constexpr ll limit = 1e6 + 9; // for some reason 1e6 is not enough

vector<ll> sieve(void) {
    bool is_prime[limit];
    fill(is_prime, is_prime + limit, true);
    vector<ll> primes;

    for (ll i = 2; i < limit; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = i * i; j < limit; j += i)
                is_prime[j] = false;
        }
    }

    return primes;
}

ll count_semiprimes(vector<ll>& primes, ll largest) {
    if (largest < 4)
        return 0;

    ll count = 0;
    ll end = primes.size() - 1;

    for (ll i = 0; i < primes.size(); i++) {
        while (end >= 0 && primes[i] * primes[end] > largest)
            end--;
        if (end < i)
            break;
        else
            count += end - i + 1;
    }

    return count;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a, b;
    cin >> a >> b;

    vector<ll> primes = sieve();

    ll result = count_semiprimes(primes, b) - count_semiprimes(primes, a - 1);

    cout << result << '\n';

    return 0;
}
