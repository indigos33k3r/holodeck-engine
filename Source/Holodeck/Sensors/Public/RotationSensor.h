// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "Holodeck.h"

#include "HolodeckSensor.h"

#include "RotationSensor.generated.h"

/**
* RotationSensor
* Inherits from the HolodeckSensor class
* Check out the parent class for documentation on all of the overridden funcions.
* Gets the true rotation of the component that the sensor is attached to.
*/
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class HOLODECK_API URotationSensor : public UHolodeckSensor {
	GENERATED_BODY()

public:
	/**
	* Default Constructor
	*/
	URotationSensor	();

	/**
	* BeginPlay
	* Called at the start of the game.
	*/
	void BeginPlay() override;

protected:
	//See HolodeckSensor for the documentation of these overridden functions.
	FString GetDataKey() override { return "RotationSensor"; };
	int GetNumItems() override { return 3; };
	int GetItemSize() override { return sizeof(float); };
	void TickSensorComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	/**
	* Parent
	* After initialization, Parent contains a pointer to whatever the sensor is attached to.
	*/
	AActor* Parent;

};
