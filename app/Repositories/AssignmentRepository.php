<?php

namespace App\Repositories;

use App\Models\Assignment;
use App\Repositories\BaseRepository;

/**
 * Class AssignmentRepository
 * @package App\Repositories
 * @version February 18, 2022, 11:52 am UTC
*/

class AssignmentRepository extends BaseRepository
{
    /**
     * @var array
     */
    protected $fieldSearchable = [
        'characters',
        'expiry_date',
        'attempt_status',
        'activation_status'
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
        return Assignment::class;
    }
}
