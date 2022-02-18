<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class HomeController extends Controller
{
    /**
     * Create a new controller instance.
     *
     * @return void
     */
    public function __construct()
    {
        $this->middleware('auth');
    }

    /**
     * Show the application dashboard.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        $attempted = \App\Models\Attempt::distinct('assignment_id')->count();
        $notattempted= \App\Models\Assignment::count() -  $attempted;
        return view('dashboard',compact('attempted','notattempted'));
    }
}
