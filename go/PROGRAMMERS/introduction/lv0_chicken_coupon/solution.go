package lv1_character_go

func calc(chicken int) (int, int) {
	bonus, coupon := 0, 0
	for chicken > 0 {
		bonus += chicken / 10
		coupon += chicken % 10
		chicken /= 10
	}
	return bonus, coupon
}

func solution(chicken int) int {
	bonus, coupon := 0, 0
	for chicken >= 10 {
		chicken, coupon = calc(chicken)
		bonus += chicken
		chicken = coupon
	}

	return bonus
}
