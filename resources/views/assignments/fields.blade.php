<!-- Characters Field -->
<div class="form-group col-sm-6">
    {!! Form::label('characters', 'Characters:') !!}
    {!! Form::text('characters', null, ['class' => 'form-control','maxlength' => 255,'maxlength' => 255]) !!}
</div>

<!-- Expiry Date Field -->
<div class="form-group col-sm-6">
    {!! Form::label('expiry_date', 'Expiry Date:') !!}
    {!! Form::date('expiry_date', null, ['class' => 'form-control','id'=>'expiry_date']) !!}
</div>


<!-- Attempt Status Field -->
<div class="form-group col-sm-6">
    {!! Form::text('attempt_status', null, ['class' => 'form-control','maxlength' => 255,'maxlength' => 255,'hidden']) !!}
</div>

<!-- Activation Status Field -->
<div class="form-group col-sm-6">
    {!! Form::label('activation_status', 'Activation Status:') !!}
    {!! Form::select('activation_status', ['activated'=>'activated','deactivated'=>'deactivated'], ['class' => 'form-control','maxlength' => 255,'maxlength' => 255]) !!}
</div>