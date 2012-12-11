<?php

namespace erpal_crm_mailaction\misc;

/**
 * This function is an helper for creating an object of a class,
 * by-passing constructor arguments and calling a method of the object
 * with arguments.
 * 
 * @param   string $class_name            The name of the class.
 * @param   string $method_name           The name of the method.
 * @param   array  $constructor_arguments An array of arguments which will be by-passed to the constructor.
 * @param   ...                           Each further argument will be by-passed to the method call.
 * @return  object                        An object of the class.
 */
function call_object_callback_new_object ($class_name, $method_name, $constructor_arguments) {

  static $classes = array ();

  if (! isset ($className[$class_name])) {
    $reclection = new \ReflectionClass($class_name);
    $className[$class_name]  = $reclection->newInstanceArgs($constructor_arguments);
  }

  return call_user_func_array(
    array ($className[$class_name], $method_name),
    count (func_get_args ()) <= 3 ? array () : array_splice (func_get_args (), 3)
  );
}

/**
 * This function is an helper for creating an object of a class,
 * by-passing constructor arguments and calling a method of the object
 * with arguments.
 * 
 * @param   string $object                The object.
 * @param   string $method_name           The name of the method.
 * @param   array  $constructor_arguments An array of arguments which will be by-passed to the constructor.
 * @param   ...                           Each further argument will be by-passed to the method call.
 * @return  object                        An object of the class.
 */
function call_object_callback_ ($object, $method_name, $constructor_arguments) {

  return call_user_func_array(
    array ($object, $method_name),
    count (func_get_args ()) <= 3 ? array () : array_splice (func_get_args (), 3)
  );
}
