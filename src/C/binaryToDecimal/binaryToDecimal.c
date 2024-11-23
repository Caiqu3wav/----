unsigned bin_to_decimal(const char *bin) {
  int dec = 0;
  int comprimento = strlen(bin);
  
  for (int i = 0; i < comprimento; i++) {
    char c = bin[i];
    dec = dec * 2 + (c - '0');
  }
	return dec;
}

int main() {
  printf("%u\n", bin_to_decimal("101010"));
  return 0;
}