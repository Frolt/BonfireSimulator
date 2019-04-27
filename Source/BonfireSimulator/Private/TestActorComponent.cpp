// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActorComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values for this component's properties
UTestActorComponent::UTestActorComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	CapsuleCollision = CreateDefaultSubobject<UCapsuleComponent>(FName("TestCapsule"));

	auto Owner = GetOwner();
	if (Owner)
	{
		UE_LOG(LogTemp, Warning, TEXT("Owner is: %s"), *GetOwner()->GetName());
		CapsuleCollision->SetupAttachment(GetOwner()->GetRootComponent());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("NO OWNER"));
	}
}


// Called when the game starts
void UTestActorComponent::BeginPlay()
{
	Super::BeginPlay();

	if (GetOwner())
	{
		UE_LOG(LogTemp, Warning, TEXT("Owner is: %s"), *GetOwner()->GetName());
	}
	
}


// Called every frame
void UTestActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

