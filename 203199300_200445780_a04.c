
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

        
      
        

  
  
  
}


  

  
