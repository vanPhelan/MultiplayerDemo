// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectorComponent.h"
#include "Projectile.h"

// Sets default values for this component's properties
UProjectorComponent::UProjectorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
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

AProjectile* UProjectorComponent::FireProjectile()
{
	AActor* owner = GetOwner();
	FVector location = GetComponentLocation();
	FRotator rotation = GetComponentRotation();
	FActorSpawnParameters spawnParameters;
	spawnParameters.Instigator = owner->GetInstigator();
	spawnParameters.Owner = owner;
	AProjectile* projectile = GetWorld()->SpawnActor<AProjectile>(Projectile, location, rotation, spawnParameters);

	projectile->Mesh->AddForce(FVector(10.0f, 0.0f, 0.0f));

	return projectile;
}

