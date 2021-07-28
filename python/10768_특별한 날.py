monn = int(input())
dayn = int(input())
print("Before" if (monn < 2 or (monn == 2 and dayn < 18)) else ( "Special" if(monn == 2 and dayn == 18 ) else "After"))