// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "PatrollingGuard.h"
#include "AIController.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	auto PatrollingGuard = Cast<APatrollingGuard>(OwnerComp.GetAIOwner()->GetPawn());
	auto PatrolPoints = PatrollingGuard->PatrolPointsCPP;
	
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

	BlackboardComp->SetValueAsObject(FName("Waypoint"), PatrolPoints[Index]);

	Index++;
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, Index%PatrolPoints.Num());


	UE_LOG(LogTemp, Warning, TEXT("Waypoint index = %i"), Index)
	return EBTNodeResult::Succeeded;
}
