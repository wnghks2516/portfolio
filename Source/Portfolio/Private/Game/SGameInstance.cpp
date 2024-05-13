// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/SGameInstance.h"
#include "Kismet/KismetSystemLibrary.h"
#include "SUnrealObjectClass.h"
#include "Example/SFlyable.h"
#include "Example/Spigeon.h"

USGameInstance::USGameInstance()
{
	UE_LOG(LogTemp, Log, TEXT("경고나 에러가 아닙니다."));

	Name = TEXT("USGameInstance에서 Name변수값을 설정했습니다");
}

void USGameInstance::Init()
{
	Super::Init(); // 엔진 업데이트 루틴을 지키기 위해서, 언리얼 엔지니어가 작성한 코드가 먼저 실행되게끔 하기 위함.
	
	FBirdData SrcRawData(TEXT("Pigeon17"), 17);
	UE_LOG(LogTemp, Log, TEXT("[SrcRawData] Name : %s, ID = %d"), *SrcRawData.Name, SrcRawData.ID);
	//간접경로 
	const FString SavedDir = FPaths::Combine(FPlatformMisc::ProjectDir(), TEXT("Saved"));
	UE_LOG(LogTemp, Log, TEXT("SavedDir : %s"), *SavedDir);

	//상대경로
	const FString RawDataFileName(TEXT("RawData.bin"));
	FString AbsolutePathForRawData = FPaths::Combine(*SavedDir, *RawDataFileName);
	UE_LOG(LogTemp, Log, TEXT("Relative path for saved file: %s"), *AbsolutePathForRawData);

	//절대경로
	FPaths::MakeStandardFilename(AbsolutePathForRawData);
	UE_LOG(LogTemp, Log, TEXT("Absolute path for saved file: %s"), *AbsolutePathForRawData);

	FArchive* RawFileWriterAr = IFileManager::Get().CreateFileWriter(*AbsolutePathForRawData);
	if (nullptr != RawFileWriterAr)
	{
		*RawFileWriterAr << SrcRawData;
		RawFileWriterAr->Close();
		delete RawFileWriterAr;
		RawFileWriterAr = nullptr;
	}

	FBirdData DstRawData;
	FArchive* RawFileReaderAr = IFileManager::Get().CreateFileReader(*AbsolutePathForRawData);
	if (nullptr != RawFileReaderAr)
	{
		*RawFileReaderAr << DstRawData;
		RawFileReaderAr->Close();
		delete RawFileReaderAr;
		RawFileReaderAr = nullptr;

		UE_LOG(LogTemp, Log, TEXT("[DstRawData] Name: %s, ID: %d"), *DstRawData.Name, DstRawData.ID);
	}
}

void USGameInstance::Shutdown()
{
	Super::Shutdown(); // 엔진 업데이트 루틴을 지키기 위해서, 언리얼 엔지니어가 작성한 코드가 먼저 실행되게끔 하기 위함.

	UE_LOG(LogTemp, Log, TEXT("게임이 꺼졌습니다."));

	
}
