<!-- Pupil Id Field -->
<div class="form-group col-sm-6">
    {!! Form::label('pupil_id', 'Pupil Id:') !!}
    {!! Form::number('pupil_id', null, ['class' => 'form-control']) !!}
</div>

<!-- Assignment Id Field -->
<div class="form-group col-sm-6">
    {!! Form::label('assignment_id', 'Assignment Id:') !!}
    {!! Form::number('assignment_id', null, ['class' => 'form-control']) !!}
</div>

<!-- Message Field -->
<div class="form-group col-sm-6">
    {!! Form::label('message', 'Message:') !!}
    {!! Form::text('message', null, ['class' => 'form-control','maxlength' => 255,'maxlength' => 255]) !!}
</div>