// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorPool.h"
#include "AI/Navigation/NavMeshBoundsVolume.h"


// Sets default values for this component's properties
UActorPool::UActorPool()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

AActor * UActorPool::Checkout()
{
	return NavMeshBoundsVolume;
}

void UActorPool::Return(AActor * ActorToReturn)
{
	if (!ActorToReturn)
	{
		UE_LOG(LogTemp, Error, TEXT("%s Returned null actor"), *GetName())
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("[%s] Actor returned: {%s}."), *GetName(), *ActorToReturn->GetName())
	//ActorToReturn = NavMeshBoundsVolume;
}

void UActorPool::Add(AActor * ActorToAdd)
{
	if (!ActorToAdd)
	{
		UE_LOG(LogTemp, Error, TEXT("%s Added null actor"), *GetName())
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("[%s] Actor adde: {%s}."), *GetName(), *ActorToAdd->GetName());
	//Return(ActorToAdd);
}
