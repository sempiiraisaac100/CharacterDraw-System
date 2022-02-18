<!-- Pupil Id Field -->
<div class="col-sm-12">
    {!! Form::label('pupil_id', 'Pupil Id:') !!}
    <p>{{ $attempt->pupil_id }}</p>
</div>

<!-- Assignment Id Field -->
<div class="col-sm-12">
    {!! Form::label('assignment_id', 'Assignment Id:') !!}
    <p>{{ $attempt->assignment_id }}</p>
</div>

<!-- Average Score Field -->
<div class="col-sm-12">
    {!! Form::label('average_score', 'Average Score:') !!}
    <p>{{ $attempt->average_score }}</p>
</div>

<!-- Attempt Duration In Seconds Field -->
<div class="col-sm-12">
    {!! Form::label('attempt_duration_in_seconds', 'Attempt Duration In Seconds:') !!}
    <p>{{ $attempt->attempt_duration_in_seconds }}</p>
</div>

<!-- Teacher Comment Field -->
<div class="col-sm-12">
    {!! Form::label('teacher_comment', 'Teacher Comment:') !!}
    <p>{{ $attempt->teacher_comment }}</p>
</div>

