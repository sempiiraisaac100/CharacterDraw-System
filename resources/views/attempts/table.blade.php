<div class="table-responsive">
    <table class="table" id="attempts-table">
        <thead>
        <tr>
            <th>Pupil Id</th>
        <th>Assignment Id</th>
        <th>Average Score</th>
        <th>Attempt Duration In Seconds</th>
        <th>Teacher Comment</th>
            <th>Action</th>
        </tr>
        </thead>
        <tbody>
        @foreach($attempts as $attempt)
            <tr>
                <td>{{ $attempt->pupil_id }}</td>
            <td>{{ $attempt->assignment_id }}</td>
            <td>{{ $attempt->average_score }}</td>
            <td>{{ $attempt->attempt_duration_in_seconds }}</td>
            <td>{{ $attempt->teacher_comment }}</td>
                <td width="120">
                    {!! Form::open(['route' => ['attempts.destroy', $attempt->id], 'method' => 'delete']) !!}
                    <div class='btn-group'>
                        <a href="{{ route('attempts.show', [$attempt->id]) }}"
                           class='btn btn-default btn-xs'>
                            <i class="far fa-eye"></i>
                        </a>
                        <a href="{{ route('attempts.edit', [$attempt->id]) }}"
                           class='btn btn-default btn-xs'>
                            <i class="far fa-edit"></i>
                        </a>
                    </div>
                    {!! Form::close() !!}
                </td>
            </tr>
        @endforeach
        </tbody>
    </table>
</div>
@push('third_party_stylesheets')
{{-- <link rel="stylesheet" type="text/css" href="https://cdn.datatables.net/1.11.4/css/jquery.dataTables.css"> --}}
<link rel="stylesheet" type="text/css" href="https://cdn.datatables.net/v/dt/jszip-2.5.0/dt-1.11.4/b-2.2.2/b-colvis-2.2.2/b-html5-2.2.2/b-print-2.2.2/sc-2.0.5/datatables.min.css"/>

     <!-- DataTables -->
  {{-- <link rel="stylesheet" href="{{URL::asset('assets/adminite/plugins/datatables-bs4/css/dataTables.bootstrap4.min.css')}}">
  <link rel="stylesheet" href="{{URL::asset('assets/adminite/plugins/datatables-responsive/css/responsive.bootstrap4.min.css')}}"> --}}
@endpush
@push('third_party_scripts')
 
<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/pdfmake/0.1.36/pdfmake.min.js"></script>
<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/pdfmake/0.1.36/vfs_fonts.js"></script>
<script type="text/javascript" src="https://cdn.datatables.net/v/dt/jszip-2.5.0/dt-1.11.4/b-2.2.2/b-colvis-2.2.2/b-html5-2.2.2/b-print-2.2.2/sc-2.0.5/datatables.min.js"></script>
@endpush
@push('page_scripts')
    <script>
         $(function () {
            $('#attempts-table').DataTable({
                  'destroy': false,
                  dom: 'Bfrtip',
                  buttons: [
                        {
                    extend: 'copyHtml5',
                    exportOptions: {
                        columns: [ 0,1,2,3,4]
                    }   
                },
                {
                    extend: 'excelHtml5',
                    exportOptions: {
                        columns: [0,1,2,3,4]
                    }
                },
                {
                    extend: 'pdfHtml5',
                    exportOptions: {
                        columns: [ 0, 1,2,3,4]
                    }
                },
                {
                    extend: 'csvHtml5',
                    exportOptions: {
                        columns: [ 0, 1,2,3,4]
                    }
                },
                  ]
              });
        });
    </script>
@endpush