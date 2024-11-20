// the aim of this program is to use Windows API in displaying and updating the timestramps of a certain file, inputted by the user. 
// the program will update the file's last written time to the current system time. 
// improvement needed: print error message instead of error code.

#include<windows.h>
#include<stdio.h>

void displayFileTime(LPCSTR typeOfTime, FILETIME fileTime) {
	SYSTEMTIME systemTime;
	FileTimeToSystemTime(&fileTime, &systemTime);
	printf("%s: %04d-%02d-%02d %02d:%02d:%02d\n", typeOfTime,
	       systemTime.wYear, systemTime.wMonth, systemTime.wDay,
	       systemTime.wHour, systemTime.wMinute, systemTime.wSecond);
} // end of displayFileTime function


int main() {

	char filePath[MAX_PATH];
	printf("Enter the file path: ");
	gets(filePath);

	HANDLE hFile = CreateFileA(filePath, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if(hFile == INVALID_HANDLE_VALUE) {
		printf("Error! Could not access the file.\nError %lu.\n", GetLastError());
		return 1;
	}

	// retrieves file time information
	FILETIME cTime, aTime, wTime; // Creation time, Last Access time, Last Write time.
	if(!GetFileTime(hFile, &cTime, &aTime, &wTime)) {
		printf("Error! Could not retrieve file time information.\nError %lu.\n", GetLastError());
		CloseHandle(hFile);
		return 1;
	}


	// display file time information
	printf("\nOriginal Timestamps: \n");
	displayFileTime("Creation Time", cTime);
	displayFileTime("Last Access Time", aTime);
	displayFileTime("Last Write Time", wTime);


	// updates the last write time of file to the current system time
	FILETIME lastFileWriteTime; // last write time
	SYSTEMTIME currSysTime; // current system time

	GetSystemTime(&currSysTime);
	SystemTimeToFileTime(&currSysTime, &lastFileWriteTime);

	if(!SetFileTime(hFile, NULL, NULL, &lastFileWriteTime)) {
		printf("Error! Could not update the last write time to system time.\nError %lu.\n", GetLastError());
		CloseHandle(hFile);
		return 1;
	} 
	
	else {
		// If Updation is successful.
		printf("\nUpdating Last Write Time to current system time... \nLast Write Time successfully updated.");

		printf("\nUpdated Last Write Time");
		displayFileTime("", lastFileWriteTime);
		CloseHandle(hFile);

		printf("\nProgram Completed.\n");
	}
	return 0;
}
