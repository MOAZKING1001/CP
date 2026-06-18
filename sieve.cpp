bitset<100000> compo;
void sieve(int64_t n) {
  compo[0] = compo[1] = 1;
  for (int i = 2; i * i <= n; i++) {
    for (int j = i * i; j <= n; j += i) {
      compo[j] = 1;
    }
  }
}