bool isPrime(int64_t n) {
  if (n == 2) {
    return true;
  } else if (!(n % 2) || n == 1) {
    return false;
  }
  for (int64_t i = 3; i * i <= n; i += 2) {
    if (!(n % i)) {
      return false;
    }
  }
  return true;
}