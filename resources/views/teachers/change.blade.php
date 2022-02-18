@extends('layouts.app')
@section('content')
<section class="content-header">
    <div class="container-fluid">
        <div class="row mb-2">
            <div class="col-sm-6">
                <h1>Change Password</h1>
            </div>
   
        </div>
    </div>
</section>

<div class="content px-3">

    @include('flash::message')

    <div class="clearfix"></div>

    <div class="card">
        {!! Form::model(['action' => 'TeacherController@change', 'method' => 'post']) !!}

        <div class="card-body">
            <div class="row">
                <div class="form-group col-sm-12">
                    {!! Form::label('old', 'Old Password:') !!}
                    {!! Form::password('old', null, ['class' => 'form-control','maxlength' => 255,'maxlength' => 255]) !!}
                </div>
                        {!! Form::text('id', Auth::user()->id, ['class' => 'form-control','maxlength' => 255,'maxlength' => 255,'hidden']) !!}
                
                <div class="form-group col-sm-12">
                    {!! Form::label('new', 'New Password:') !!}
                    {!! Form::password('new', null, ['class' => 'form-control','maxlength' => 255,'maxlength' => 255]) !!}
                </div>

                <div class="form-group col-sm-12">
                    {!! Form::label('new_confirm', 'Confirm New Password:') !!}
                    {!! Form::password('new_confirm', null, ['class' => 'form-control','maxlength' => 255,'maxlength' => 255]) !!}
                </div>
            </div>
        </div>

        <div class="card-footer">
            {!! Form::submit('Save', ['class' => 'btn btn-primary']) !!}
        </div>

        {!! Form::close() !!}

     
    </div>
</div>
</div>
@endsection