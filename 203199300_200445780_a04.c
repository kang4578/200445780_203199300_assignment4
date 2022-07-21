
void firstFit(int process[processSize], int memory[memorySize]){
  int memoryLen=len(memory);
  int processLen=len(process);
  for(int memoryInitialValue=0; memoryInitialValue<allocateLen; memoryInitialValue++){
    for(int processInitialValue=0; processInitialValue<processLen; processInitialValue++){
      if memory[memoryInitialValue] >= process[processInitialValue] {
        memory[memoryInitialValue] = processInitialValue;
        memory[memoryInitialValue] = memory[memoryInitialValue] - process[processInitialValue];
      }
    }
    return;
  }
}


void bestFit(int process[processListSize], int memory[memoryListSize]){
  int memoryLen=len(memory);
  int processLen=len(process);
  int processInMemoryIndex[processLen];
  int smallestHoleIndex = 0;
  int smallestHoleSize = 2147483647-1;
  for(int processInitialValue=0; processInitialValue<processLen; processInitialValue++){
      for(int memoryInitialValue=0; memoryInitialValue<allocateLen; memoryInitialValue++){
        if (memory[memoryInitialValue]>=process[processInitialValue] && memory[memoryInitialValue]<smallestHoleSize){
          smallestHoleIndex=memoryInitialValue;
          smallestHoleSize=memory[memoryInitialValue];
        }
      }
    memory[smallestHoleIndex] -= process[processInitialValue];
    processInMemoryIndex[memoryInitialValue] = processInitialValue;
  }
  return processInMemoryIndex[processLen];
}
    

void worseFit(int process[processListSize], int memory[memoryListSize]) {
  int memoryLen=len(memory);
  int processLen=len(process);
  int processInMemoryIndex[processLen];
  int biggestHoleIndex = 0;
  int biggestHoleSize = 2147483647-1;
  for(int processInitialValue=0; processInitialValue<processLen; processInitialValue++){
    for(int memoryInitialValue=0; memoryInitialValue<allocateLen; memoryInitialValue++){
      if (memory[memoryInitialValue]>=process[processInitialValue] && memory[memoryInitialValue]>biggestHoleIndex){
        biggestHoleIndex=memoryInitialValue;
        biggestHoleSize=memory[memoryInitialValue];
      }
    }
    memory[biggestHoleIndex]-=process[processInitialValue];
    processInMemoryIndex[memoryInitialValue]=processInitialValue;
  }
  return processInMemoryIndex[processLen];
}



        
      
        

  
  

  

  
