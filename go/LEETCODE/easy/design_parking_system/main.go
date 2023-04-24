package main

import "fmt"

type ParkingSystem struct {
	places [3]int
}

func Constructor(big int, medium int, small int) ParkingSystem {
	return ParkingSystem{
		places: [3]int{big, medium, small},
	}
}

func (this *ParkingSystem) AddCar(carType int) bool {
	var placeNum = carType - 1

	if this.places[placeNum] <= 0 {
		return false
	}

	this.places[placeNum]--
	return true
}

func main() {
	var parkingSystem = Constructor(1, 1, 0)
	fmt.Println(parkingSystem.AddCar(1)) // return true because there is 1 available slot for a big car
	fmt.Println(parkingSystem.AddCar(2)) // return true because there is 1 available slot for a medium car
	fmt.Println(parkingSystem.AddCar(3)) // return false because there is no available slot for a small car
	fmt.Println(parkingSystem.AddCar(1)) // return false because there is no available slot for a big car. It is already occupied.
}
