// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "PatrollingGuard.h"
#include "PatrolRoute.h"
#include "AIController.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	auto PatrolRouteComponent = OwnerComp.GetAIOwner()->GetPawn()->FindComponentByClass<UPatrolRoute>();
	auto PatrolPoints = PatrolRouteComponent->GetPatrolPoints();
	
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	Index++;
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, Index%PatrolPoints.Num());


	UE_LOG(LogTemp, Warning, TEXT("Waypoint index = %i"), Index)
	return EBTNodeResult::Succeeded;
}
