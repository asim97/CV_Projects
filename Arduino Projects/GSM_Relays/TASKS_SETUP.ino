
void tasks_init() {
  /* Tasks are added to the schedule here in the form
    addTask(task_function_name, task_period, task_offset) */

  String addedTasks;
  Serial.print("Tasks Scheduler INIT -  Started\n\n");

  /* Create a schedule with 3 tasks */
  Schedule.begin(3);


  /* Add the GSM CHECK task to the schedule every 2000 'ticks' (2000ms) starting from 0 'ticks' (0ms)*/
  Schedule.addTask("GSM CHECK", check_gsm_started, 0, 2000);
  Serial.print(Schedule.lastAddedTask());
  
  /* Add the SENSORS READ task to the schedule every 3000 'ticks' (3000ms) starting from 2000 'ticks' (2000ms)*/
  Schedule.addTask("SENSORS READ", READ_SENSORS, 2000, 3000);
  Serial.print(Schedule.lastAddedTask());

  /* Add the Check Abnormal task to the schedule every 10000 'ticks' (10000ms) starting from 5000 'ticks' (5000ms)*/
  Schedule.addTask("Check Abnormal", CHECK_ABNORM, 5000, 10000);
  Serial.print(Schedule.lastAddedTask());

  /* Starting the scheduler with a tick length of 1 millisecond */
  Schedule.startTicks(1);

  /* Some error checks */
  if (Schedule.checkTooManyTasks() == true) {
    Serial.println("Too many tasks");
  }

  if (Schedule.checkTicksTooLong() == true) {
    Serial.println("Ticks too long");
  }
}

