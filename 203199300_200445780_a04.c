//First_fit: allocate the first hole that is big enough
void firstFit(int process[processSize], int memory[memorySize]){
  //here the process and the memory are two arrays contains the size of the process and memory partition
  int memoryLen=len(memory);
  int processLen=len(process);
  int processInMemoryIndex[memoryLen]
  /*processInMemoryIndex is an array with memoryLen and each index means the index of the memory, 
  the content is the processIndex, so if we find the memory index*/
  for(int processInitialValue=0; processInitialValue<processLen; processInitialValue++){
    for(int memoryInitialValue=0; memoryInitialValue<allocateLen; memoryInitialValue++){
      if memory[memoryInitialValue] >= process[processInitialValue] {
        memory[memoryInitialValue] = processInitialValue;
        memory[memoryInitialValue] = memory[memoryInitialValue] - process[processInitialValue];
        processInMemoryIndex[memoryInitialValue]=processInitialValue
        break:
        // if we find the first hole which fit the process, we just out the memory loop to find the next process
      }
    }
    return processInMemoryIndex;
  }
}

//Best-fit:  Allocate the smallest hole that is big enough; must search entire list, unless ordered by size
void bestFit(int process[processListSize], int memory[memoryListSize]){
  int memoryLen=len(memory);
  int processLen=len(process);
   /*processInMemoryIndex is an array with memoryLen and each index means the index of the memory, 
  the content is the processIndex, so if we find the memory index*/
  int processInMemoryIndex[processLen];
  //here we set a smallestholesize and index to make sure that after the loop we can find the smallest fit hole again
  int smallestHoleIndex = 0;
  int smallestHoleSize = 2147483647-1; //the biggest number in C
  for(int processInitialValue=0; processInitialValue<processLen; processInitialValue++){
      for(int memoryInitialValue=0; memoryInitialValue<allocateLen; memoryInitialValue++){
        if (memory[memoryInitialValue]>=process[processInitialValue] && memory[memoryInitialValue]<smallestHoleSize){
          smallestHoleIndex=memoryInitialValue;
          smallestHoleSize=memory[memoryInitialValue];
        }
      }
    //every time we have to pass the memory loop to find the smallest fit hole
    memory[smallestHoleIndex] -= process[processInitialValue];
    processInMemoryIndex[memoryInitialValue] = processInitialValue;
  }
  return processInMemoryIndex;
}
    
//Worst-fit:  Allocate the largest hole; must also search entire list
void worseFit(int process[processListSize], int memory[memoryListSize]) {
  int memoryLen=len(memory);
  int processLen=len(process);
  /*processInMemoryIndex is an array with memoryLen and each index means the index of the memory, 
  the content is the processIndex, so if we find the memory index*/
  int processInMemoryIndex[processLen];
  int biggestHoleIndex = 0;
  int biggestHoleSize = 0; //because every hole size is larger than 0, so we set the initial value to 0 here
  for(int processInitialValue=0; processInitialValue<processLen; processInitialValue++){
    for(int memoryInitialValue=0; memoryInitialValue<allocateLen; memoryInitialValue++){
      if (memory[memoryInitialValue]>=process[processInitialValue] && memory[memoryInitialValue]>biggestHoleIndex){
        biggestHoleIndex=memoryInitialValue;
        biggestHoleSize=memory[memoryInitialValue];
      }
    }
    //every time we have to pass the memory list to find the biggest hole and then we loop the process
    memory[biggestHoleIndex]-=process[processInitialValue];
    processInMemoryIndex[memoryInitialValue]=processInitialValue;
  }
  return processInMemoryIndex;
}


void main(int process[processSize], int memory[memorySize]){
  int res;
  int countFreeSize=0;
  printf("Please enter which kind of fit you want to use: ")
  scanf("%s",&fit)
  if(fit=="F"){
    res=firstFit(int process[processSize], int memory[memorySize])
  }
  else if(fit=="B"){
    res=bestFit(int process[processSize], int memory[memorySize])
  }
  else if(fit=="W"){
    res=worstFit(int process[processSize], int memory[memorySize])
  }
  for(int index=0; index<processSize; index++){
    if (res[index]==NULL){
      countFreeSize+=memory[index]
    }
  }
  return countFreeSize
}

        
      
        

  
  

  

  
