#define TASK_1 0
#define TASK_2 1

void task1(long startTime, long scheduledTime);
void task2(long startTime, long scheduledTime);

byte fsm_state = TASK_1;

int task1var = 0;
int task2var = 500;

void setup()
{
	Serial.begin(9600);
  	randomSeed(100);
}
void loop()
{
	switch(fsm_state)
	{
		case TASK_1:
			digitalWrite(13, LOW);
			task1(millis(),scheduler());
			fsm_state = TASK_2;
			break;
		case TASK_2:
			digitalWrite(13, HIGH);
			task2(millis(), scheduler());
			fsm_state = TASK_1;
			break;
	}

}

void task1(long startTime, long scheduledTime)
{
  	while((millis()-startTime) <= scheduledTime)
    {
      //Check if 500
      if(task1var == 500){
        Serial.println("Task 1 completed!");
        fsm_state = TASK_2;
        break;
      }else{
		task1var++;
		Serial.println(task1var);
      }
    }
}

void task2(long startTime, long scheduledTime)
{
  
  while((millis()-startTime) <= scheduledTime)
  {
    	//Check if zero
    	if(task2var == 0){
        	Serial.println("Task 2 completed!");
          	fsm_state = TASK_1;
          	break;
        }
    	else{
        	task2var--;
			Serial.println(task2var);
        }
  }
}
//Generate time value for task
int scheduler(){
  	return random(1000);
}

