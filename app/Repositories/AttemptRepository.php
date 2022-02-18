<?php

namespace App\Repositories;

use App\Models\Attempt;
use App\Repositories\BaseRepository;

/**
 * Class AttemptRepository
 * @package App\Repositories
 * @version February 18, 2022, 12:35 pm UTC
*/

class AttemptRepository extends BaseRepository
{
    /**
     * @var array
     */
    protected $fieldSearchable = [
        'pupil_id',
        'assignment_id',
        'average_score',
        'attempt_duration_in_seconds',
        'teacher_comment'
    ];

    /**
     * Return searchable fields
     *
     * @return array
     */
    public function getFieldsSearchable()
    {
        return $this->fieldSearchable;
    }

    /**
     * Configure the Model
     **/
    public function model()
    {
        return Attempt::class;
    }
}
