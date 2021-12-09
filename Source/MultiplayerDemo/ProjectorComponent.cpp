// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectorComponent.h"
#include "Projectile.h"

// Sets default values for this component's properties
UProjectorComponent::UProjectorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	Projectile = AProjectile::StaticClass();
}


// Called when the game starts
void UProjectorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UProjectorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UProjectorComponent::Fire()
{
	SpawnProjectile();
}

void UProjectorComponent::SpawnProjectile_Implementation()
{
	AActor* owner = GetOwner();

	FVector location = GetComponentLocation();
	FRotator rotation = GetComponentRotation();
	FActorSpawnParameters spawnParameters;
	spawnParameters.Instigator = owner->GetInstigator();
	spawnParameters.Owner = owner;

	AProjectile* projectile = GetWorld()->SpawnActor<AProjectile>(Projectile, location, rotation, spawnParameters);
}

