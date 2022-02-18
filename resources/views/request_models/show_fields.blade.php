<!-- Pupil Id Field -->
<div class="col-sm-12">
    {!! Form::label('pupil_id', 'Pupil Id:') !!}
    <p>{{ $requestModel->pupil_id }}</p>
</div>

<!-- Assignment Id Field -->
<div class="col-sm-12">
    {!! Form::label('assignment_id', 'Assignment Id:') !!}
    <p>{{ $requestModel->assignment_id }}</p>
</div>

<!-- Message Field -->
<div class="col-sm-12">
    {!! Form::label('message', 'Message:') !!}
    <p>{{ $requestModel->message }}</p>
</div>

