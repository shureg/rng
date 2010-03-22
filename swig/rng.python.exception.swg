%exception
{
   try
   {
      $action
   }
   catch(const char* c)
   {
      PyErr_SetString(PyExc_Exception,c);
      return NULL;
   }
}

