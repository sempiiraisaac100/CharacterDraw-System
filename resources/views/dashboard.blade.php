@extends('layouts.app')
@section('content')
<div class="row">
    <div class="col-lg-3 col-6">
      <!-- small box -->
      <div class="small-box bg-info">
        <div class="inner">
          <h3>{{\App\Models\Pupil::whereNull('deleted_at')->count()}}</h3>

          <p>Pupils</p>
        </div>
        <div class="icon">
          <i class="ion ion-bag"></i>
        </div>
        <a href="{{ route('pupils.index') }}" class="small-box-footer">More info <i class="fas fa-arrow-circle-right"></i></a>
      </div>
    </div>
    <!-- ./col -->
    @if(Auth::user()->email =="admin@kindercare.com")
    <div class="col-lg-3 col-6">
      <!-- small box -->
      <div class="small-box bg-success">
        <div class="inner">
          <h3>{{\App\Models\Teacher::whereNull('deleted_at')->count()}}</h3>

          <p>Teachers</p>
        </div>
        <div class="icon">
          <i class="ion ion-stats-bars"></i>
        </div>
        <a href="{{ route('teachers.index') }}" class="small-box-footer">More info <i class="fas fa-arrow-circle-right"></i></a>
      </div>
    </div>
    <!-- ./col -->
    @endif
    <div class="col-lg-3 col-6">
      <!-- small box -->
      <div class="small-box bg-warning">
        <div class="inner">
          <h3>{{\App\Models\RequestModel::whereNull('deleted_at')->count()}}</h3>

          <p>Requests</p>
        </div>
        <div class="icon">
          <i class="ion ion-person-add"></i>
        </div>
        <a href="{{ route('requestModels.index') }}" class="small-box-footer">More info <i class="fas fa-arrow-circle-right"></i></a>
      </div>
    </div>
    <!-- ./col -->
    <div class="col-lg-3 col-6">
      <!-- small box -->
      <div class="small-box bg-danger">
        <div class="inner">
          <h3>{{\App\Models\Assignment::whereNull('deleted_at')->count()}}
        </h3>

          <p>Assignments</p>
        </div>
        <div class="icon">
          <i class="ion ion-pie-graph"></i>
        </div>
        <a href="{{ route('assignments.index') }}" class="small-box-footer">More info <i class="fas fa-arrow-circle-right"></i></a>
      </div>
    </div>
    <!-- ./col -->

    <div class="col-md-6">
        <!-- PIE CHART -->
        <div class="card card-danger">
          <div class="card-header">
            <h3 class="card-title">Assignment Pie Chart</h3>

            <div class="card-tools">
              <button type="button" class="btn btn-tool" data-card-widget="collapse"><i class="fas fa-minus"></i>
              </button>
              <button type="button" class="btn btn-tool" data-card-widget="remove"><i class="fas fa-times"></i></button>
            </div>
          </div>
          <div class="card-body">
            <canvas id="pieChartAsg" style="min-height: 250px; height: 250px; max-height: 250px; max-width: 100%;"></canvas>
          </div>
          <!-- /.card-body -->
        </div>
        <!-- /.card -->
  </div>
</div>
@endsection
@push('page_scripts')
<script src="{{URL::asset('assets/adminite/plugins/chart.js/Chart.min.js')}}"></script>

<script>

    var pieChartCanvas = document.getElementById('pieChartAsg').getContext('2d');
    var jsAttempt  = "<?php echo $attempted ?>";
    var nonjsAttempt =  "<?php echo  $notattempted  ?>";   
    var pieChart = new Chart(pieChartCanvas, {
    type: 'pie',
    data: {
        labels: [
            'Attempted',
            'Not Attempted'
        ],
        datasets: [{
            data: [jsAttempt,nonjsAttempt],
            backgroundColor: [
                'rgba(255, 99, 132, 0.2)',
                'rgba(54, 162, 235, 0.2)'
            ]
        }]
    }
    });

    var pieChartCanvas = document.getElementById('pieChartStd').getContext('2d');

    var pieChart = new Chart(pieChartCanvas, {
    type: 'pie',
    data: {
        labels: [
            'Attempted',
            'Not Attempted'
        ],
        datasets: [{
            data: [28,20],
            backgroundColor: [
                'rgba(255, 99, 132, 0.2)',
                'rgba(54, 162, 235, 0.2)'
            ]
        }]
    }
    })
    
</script>
@endpush