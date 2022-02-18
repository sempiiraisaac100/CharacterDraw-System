<!-- Characters Field -->
<div class="col-sm-12">
    {!! Form::label('characters', 'Characters:') !!}
    <p>{{ $assignment->characters }}</p>
</div>

<!-- Expiry Date Field -->
<div class="col-sm-12">
    {!! Form::label('expiry_date', 'Expiry Date:') !!}
    <p>{{ $assignment->expiry_date }}</p>
</div>

<!-- Attempt Status Field -->
<div class="col-sm-12">
    {!! Form::label('attempt_status', 'Attempt Status:') !!}
    <p>{{ $assignment->attempt_status }}</p>
</div>

<!-- Activation Status Field -->
<div class="col-sm-12">
    {!! Form::label('activation_status', 'Activation Status:') !!}
    <p>{{ $assignment->activation_status }}</p>
</div>

