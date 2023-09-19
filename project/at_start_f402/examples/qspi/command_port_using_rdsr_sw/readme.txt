/**
  **************************************************************************
  * @file     readme.txt 
  * @brief    readme
  **************************************************************************
  */

  this demo is based on the at-start board, in this demo, systick used for 
  delay function. qspi command port operate erase/write/read with polling,
  rdsr using software mode, if qspi test pass, led3 fresh, else led2 fresh.
  the qspi flash is esmt32m. 
  - qspi io0   --->   pa6
  - qspi io1   --->   pa7
  - qspi io2   --->   pb3
  - qspi io3   --->   pa15
  - qspi sck   --->   pb2
  - qspi cs    --->   pb6

  for more detailed information. please refer to the application note document AN0088.