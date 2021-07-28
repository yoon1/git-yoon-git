S,K,H = map(int, input().split())
min = ( "Soongsil" if (S < K and S < H) else ( "Korea"  if( K < S and K < H ) else "Hanyang"))
if ( S + K + H < 100) :
    print(min)
else :
    print('OK')

