<?php
$_POST = json_decode( file_get_contents("php://input"), true ); /*-- ONLY FOR DECODE JSON */
echo var_dump($_POST);