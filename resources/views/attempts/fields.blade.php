<!-- Pupil Id Field -->
<div class="form-group col-sm-6">
    {!! Form::number('pupil_id', null, ['class' => 'form-control','hidden']) !!}
</div>

<!-- Assignment Id Field -->
<div class="form-group col-sm-6">
    {!! Form::number('assignment_id', null, ['class' => 'form-control','hidden']) !!}
</div>

<!-- Average Score Field -->
<div class="form-group col-sm-6">
    {!! Form::number('average_score', null, ['class' => 'form-control','hidden']) !!}
</div>

<!-- Attempt Duration In Seconds Field -->
<div class="form-group col-sm-6">
    {!! Form::number('attempt_duration_in_seconds', null, ['class' => 'form-control','hidden']) !!}
</div>

<!-- Teacher Comment Field -->
<div class="form-group col-sm-6">
    {!! Form::label('teacher_comment', 'Teacher Comment:') !!}
    {!! Form::text('teacher_comment', null, ['class' => 'form-control','maxlength' => 255,'maxlength' => 255]) !!}
</div>