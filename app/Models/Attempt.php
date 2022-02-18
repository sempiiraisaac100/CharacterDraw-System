<?php

namespace App\Models;

use Eloquent as Model;
use Illuminate\Database\Eloquent\SoftDeletes;
use Illuminate\Database\Eloquent\Factories\HasFactory;

/**
 * Class Attempt
 * @package App\Models
 * @version February 18, 2022, 12:35 pm UTC
 *
 * @property integer $pupil_id
 * @property integer $assignment_id
 * @property number $average_score
 * @property number $attempt_duration_in_seconds
 * @property string $teacher_comment
 */
class Attempt extends Model
{
    use SoftDeletes;

    use HasFactory;

    public $table = 'attempt';
    
    const CREATED_AT = 'created_at';
    const UPDATED_AT = 'updated_at';


    protected $dates = ['deleted_at'];



    public $fillable = [
        'pupil_id',
        'assignment_id',
        'average_score',
        'attempt_duration_in_seconds',
        'teacher_comment'
    ];

    /**
     * The attributes that should be casted to native types.
     *
     * @var array
     */
    protected $casts = [
        'id' => 'integer',
        'pupil_id' => 'integer',
        'assignment_id' => 'integer',
        'average_score' => 'float',
        'attempt_duration_in_seconds' => 'float',
        'teacher_comment' => 'string'
    ];

    /**
     * Validation rules
     *
     * @var array
     */
    public static $rules = [
        'pupil_id' => 'required|integer',
        'assignment_id' => 'required|integer',
        'average_score' => 'required|numeric',
        'attempt_duration_in_seconds' => 'required|numeric',
        'teacher_comment' => 'required|string|max:255',
        'deleted_at' => 'nullable',
        'created_at' => 'nullable',
        'updated_at' => 'nullable'
    ];

    
}
