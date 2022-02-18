<?php

use Illuminate\Support\Facades\Route;

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/
Auth::routes(['register'=>false]);

Route::middleware(['auth:web', 'verified'])->group(function () {

    Route::get('/home',[App\Http\Controllers\HomeController::class,'index']);
    Route::get('/',[App\Http\Controllers\HomeController::class,'index']);


    Route::resource('teachers', App\Http\Controllers\TeacherController::class);


    Route::resource('pupils', App\Http\Controllers\PupilController::class);


    Route::resource('assignments', App\Http\Controllers\AssignmentController::class);


    Route::resource('attempts', App\Http\Controllers\AttemptController::class);


    Route::resource('requestModels', App\Http\Controllers\RequestModelController::class);


    Route::resource('requestModels', App\Http\Controllers\RequestModelController::class);

    Route::view('/changepassword','teachers.change');
    Route::post('/changepassword',[App\Http\Controllers\TeacherController::class,'change']);
});

