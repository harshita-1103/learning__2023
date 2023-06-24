#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[9];
} LogEntry;

int readLogFile(LogEntry logEntries[]) {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Unable to open the log file.\n");
        return 0;
    }

    char line[100];
    int entryCount = 0;

    // Read the file line by line
    while (fgets(line, sizeof(line), file) != NULL) {
        // Skip the header line
        if (strstr(line, "EntryNo") != NULL)
            continue;

        // Parse the line and populate the log entry structure
        sscanf(line, "%d,%[^,],%f,%d,%d,%[^,\n]", &logEntries[entryCount].entryNo,
               logEntries[entryCount].sensorNo, &logEntries[entryCount].temperature,
               &logEntries[entryCount].humidity, &logEntries[entryCount].light,
               logEntries[entryCount].timestamp);

        entryCount++;

        if (entryCount >= MAX_ENTRIES)
            break;
    }

    fclose(file);
    return entryCount;
}

void displayLogEntries(LogEntry logEntries[], int entryCount) {
    printf("Log Entries:\n");
    printf("-------------------------------------------------------\n");
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTimestamp\n");
    printf("-------------------------------------------------------\n");

    for (int i = 0; i < entryCount; i++) {
        printf("%d\t%s\t\t%.2f\t\t%d\t\t%d\t%s\n", logEntries[i].entryNo,
               logEntries[i].sensorNo, logEntries[i].temperature,
               logEntries[i].humidity, logEntries[i].light, logEntries[i].timestamp);
    }
}

int main() {
    LogEntry logEntries[MAX_ENTRIES];
    int entryCount = readLogFile(logEntries);

    if (entryCount > 0) {
        displayLogEntries(logEntries, entryCount);
    } else {
        printf("No log entries found.\n");
    }

    return 0;
}
