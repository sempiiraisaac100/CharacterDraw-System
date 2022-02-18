<?php

namespace App\Repositories;

use App\Models\Pupil;
use App\Repositories\BaseRepository;

/**
 * Class PupilRepository
 * @package App\Repositories
 * @version February 18, 2022, 12:33 pm UTC
*/

class PupilRepository extends BaseRepository
{
    /**
     * @var array
     */
    protected $fieldSearchable = [
        'pupil_name'
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
        return Pupil::class;
    }
}
