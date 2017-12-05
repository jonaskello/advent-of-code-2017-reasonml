/*

   e e e e e e e e e e e
   e d d d d d d d d d e
   e d c c c c c c c d e
   e d c b b b b b c d e
   e d c b a a a b c d e
   e d c b a X a b c d e
   e d c b a a a b c d e
   e d c b b b b b c d e
   e d c c c c c c c d e
   e d d d d d d d d d e
   e e e e e e e e e e e

   X = 1 * 4 - 4 = 0
   a = 3 * 4 - 4 = 8   (1-8)   (max=8+0=8)
   b = 5 * 4 - 4 = 16  (9-24)  (max=8+16=24)
   c = 7 * 4 - 4 = 24  (25-48) (max=24+24=48)
   d = 9 * 4 - 4 = 32  (X-X)   (48+32=80)
   e = 11 * 4 - 4 = 40 (X-X)   (80+40=120)
   f = 13 * 4 - 4 = 48 (X-X)   (120+48=168)

  The number of digits per layer increases with 8 digits for each layer
  Layer 0 has 1 digit
  Layer 1 has 8 digits
  Layer 2 has 16 digits
  Layer 3 has 24 digits
  Layer 4 has 32 digits
  Layer n has n * 8 digits

  The max number of each layer is the sum the number of digits in each layer before it + its own number of digits.

  The max number in layer 1 is 8
  The max number in layer 2 is 8+16=24
  The max number in layer 3 is 8+16+24=48
  The max number in layer 4 is 8+16+24+32=80
  The max number in layer 5 is 8+16+24+32+40=120
  The max number in layer n is (n * 8 + (n-1) * 8 + (n-2) * 8 + ... + (n-n) * 8)


 */
let x = 1;